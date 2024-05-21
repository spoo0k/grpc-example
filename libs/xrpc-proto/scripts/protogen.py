import os
import sys
import subprocess
import shutil
import argparse

try:
    from termcolor import colored
except ModuleNotFoundError:
    def colored(text, color=None):
        return text


def getroot(foldername: str) -> str:
    __root = os.path.abspath(os.path.dirname(__file__))
    if os.path.basename(__root) == foldername:
        __root = os.path.abspath(os.path.join(__root, ".."))
    print(colored(f'- project root directory: {__root}', "magenta"))
    return __root


def find_executable(name: str):
    try:
        _a = subprocess.run(f'{name} --version', shell=True, stdout=subprocess.DEVNULL)
        if _a.returncode != 0:
            raise FileNotFoundError
        print(colored(f'- {name} found ({_a.stdout if _a.stdout else _a.stderr if _a.stderr else "unknown version"})', "green"))
    except FileNotFoundError:
        print(colored(f'- {name} not found', "red"))
        raise FileNotFoundError
    

def normalize_path(path: str) -> str:
    if os.name == 'nt':
        return path.replace('/', '\\')
    return path


def find_executable_path(name: str) -> str:
    if os.name == 'nt':
        command = 'where'
    else:
        command = 'which'
    res = subprocess.run(f'{command} {name}', shell=True, stdout=subprocess.PIPE).stdout.decode('utf-8').strip()
    if not res:
        raise FileNotFoundError
    print(f'- found {colored(name, "green")}: {colored(res, "yellow")}')
    return res


def test_directory(path: str):
    if not os.path.exists(path):
        raise RuntimeError(f'directory not found: {path}')
    if not os.path.isdir(path):
        raise RuntimeError(f'path is not a directory: {path}')
    if not os.access(path, os.R_OK):
        raise RuntimeError(f'protobufs directory is not readable: {path}')
    

def move_header(protofile, extension: str, target_folder: str, root: str, header_out: str):
    generated_header = os.path.join(target_folder, protofile.replace(".proto", extension))
    folder = os.path.join(root, header_out)
    if not os.path.exists(folder):
        os.makedirs(folder)
        print(f'- created folder: {folder}')
    if os.path.exists(generated_header):
        shutil.move(generated_header, os.path.join(folder, protofile.replace(".proto", extension)))
    else:
        raise RuntimeError(f'generated header file not found: {generated_header}')


def generate(pb_folder: str, root: str, header_out: str, target_folder: str):
    test_directory(pb_folder)
    pb_folder_relative = f'.{os.path.sep}{os.path.relpath(pb_folder, root)}'
    for protofile in os.listdir(pb_folder):
        if protofile.endswith(".proto"):
            print(f'- generating file {colored(protofile, "green")}')
            protoc_result = subprocess.run(
                f'protoc --proto_path {pb_folder_relative} '
                f'--cpp_out={target_folder} {os.path.join(pb_folder_relative, protofile)} '
                f'--experimental_allow_proto3_optional',
                shell=True
            )
            if protoc_result.returncode != 0:
                raise RuntimeError(f'failed to generate proto file: {protofile}')
            move_header(protofile, ".pb.h", target_folder, root, header_out)
            

def generate_grpc(pb_folder: str, root: str, header_out: str, target_folder: str):
    import_folder_relative = f'.{os.path.sep}{os.path.relpath(pb_folder, root)}'
    print(f'- imports folder: {import_folder_relative}')
    print(f'- found {colored("grpc", "green")} directory. generating grpc files')
    grpc_plugin = find_executable_path('grpc_cpp_plugin')
    pb_folder = os.path.join(pb_folder, 'grpc')
    test_directory(pb_folder)
    pb_folder_relative = f'.{os.path.sep}{os.path.relpath(pb_folder, root)}'
    for protofile in os.listdir(pb_folder):
        if protofile.endswith(".proto"):
            print(f'- generating file {colored(protofile, "green")}')
            protoc_result = subprocess.run(
                f'protoc --proto_path {pb_folder_relative} '
                f'--proto_path {import_folder_relative} '
                f'--grpc_out={target_folder} --plugin=protoc-gen-grpc={grpc_plugin} '
                f'{os.path.join(pb_folder_relative, protofile)} '
                f'--cpp_out={target_folder} '
                f'--experimental_allow_proto3_optional',
                shell=True
            )
            if protoc_result.returncode != 0:
                raise RuntimeError(f'failed to generate proto file: {protofile}')
            move_header(protofile, ".grpc.pb.h", target_folder, root, header_out)
            move_header(protofile, ".pb.h", target_folder, root, header_out)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--scripts-folder', type=str, default="scripts", help="scripts folder")
    parser.add_argument('--target', type=str, required=True, help="cmake target build folder")
    parser.add_argument('--proto', type=str, required=True, help="protobufs directory")
    parser.add_argument('--header-out', type=str, required=True, help="header out directory")
    args = parser.parse_args()

    header_out = normalize_path(args.header_out)
    if not os.path.exists(header_out):
        os.makedirs(header_out)
        print(colored(f'- header out folder created: {header_out}', "magenta"))
    print(colored(f'- header out folder: {header_out}', "magenta"))

    print(colored(f'- scripts folder: {args.scripts_folder}', "magenta"))
    print(colored(f'- target build folder: {args.target}', "magenta"))
    print(colored(f'- protobufs directory: {args.proto}', "magenta"))

    if not os.path.exists(args.target):
        os.makedirs(args.target)
        print(colored(f'- target build folder created: {args.target}', "magenta"))
    print(colored("generating proto files...", "white"))
    try:
        root = getroot("scripts")
        find_executable("protoc")
        protobufs_folder = os.path.join(root, args.proto)
        print(f'- protobufs directory: {f".{os.path.sep}{os.path.relpath(protobufs_folder, root)}"}')

        generate(protobufs_folder, root, header_out, args.target)
        if(os.path.exists(os.path.join(protobufs_folder, 'grpc'))):
            generate_grpc(protobufs_folder, root, header_out, args.target)
    except RuntimeError as e:
        print(colored(f'⚠️ failed to generate proto files due to: {e}', "red"))
        sys.exit(1)
    print(colored("generating proto files finished", "green"))


if __name__ == "__main__":
    main()
