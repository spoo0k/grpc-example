cmake_minimum_required(VERSION 3.27 )

include_guard(GLOBAL)

project(xrpc-template
        VERSION 0.0.1
        DESCRIPTION "XRpc subproject for precompiled protobufs"
        HOMEPAGE_URL "com.radar-mms.uav"
        LANGUAGES C CXX
)

if(NOT CMAKE_CXX_STANDARD)
  message(STATUS "[${PROJECT_NAME}] setting c++ standard to c++20")
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if("${CMAKE_GENERATOR}" MATCHES "^Visual Studio")
  set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "" FORCE)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
message(STATUS "[${PROJECT_NAME}] setting fPIC: ${CMAKE_POSITION_INDEPENDENT_CODE}")

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

add_library(${PROJECT_NAME})
add_library(xrpc::protobufs ALIAS ${PROJECT_NAME})

message(STATUS "[${PROJECT_NAME}] generating protobuf files...")
message(STATUS "[${PROJECT_NAME}] command: ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/generate-protobufs.py")

#execute_process(
#        COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/generate-protobufs.py --target ${CMAKE_CURRENT_BINARY_DIR} --proto ${CMAKE_CURRENT_SOURCE_DIR}/src/proto
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#)

#file(GLOB PROTO_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/xrpc/protobufs/*.h")
#file(GLOB PROTO_SOURCES "${CMAKE_CURRENT_BINARY_DIR}/*.pb.cc")
#set(PROTO_HEADER_PATH_B "${CMAKE_CURRENT_SOURCE_DIR}/include/xrpc/protobufs")
#set(PROTO_HEADER_PATH_I "include/xrpc/protobufs")
#message(STATUS "[${PROJECT_NAME}] protobuf headers: ${PROTO_HEADERS}")
#message(STATUS "[${PROJECT_NAME}] protobuf sources: ${PROTO_SOURCES}")
target_sources(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/xrpc/client/x-client.h> $<INSTALL_INTERFACE:include/xrpc/client/x-client.h>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/xrpc/server/x-server.h> $<INSTALL_INTERFACE:include/xrpc/server/x-server.h>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/xrpc/proto/math.pb.h> $<INSTALL_INTERFACE:include/xrpc/proto/math.pb.h>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/xrpc/proto/math.grpc.pb.h> $<INSTALL_INTERFACE:include/xrpc/proto/math.grpc.pb.hh>
#        $<BUILD_INTERFACE:${PROTO_HEADER_PATH_B}/xrpc-test.pb.h> $<INSTALL_INTERFACE:${PROTO_HEADER_PATH_I}/xrpc-test.pb.h>
#        $<BUILD_INTERFACE:${PROTO_HEADER_PATH_B}/xrpc-test.grpc.pb.h> $<INSTALL_INTERFACE:${PROTO_HEADER_PATH_I}/xrpc-test.grpc.pb.h>
#        $<BUILD_INTERFACE:${PROTO_HEADER_PATH_B}/xrpc-test.pb.h> $<INSTALL_INTERFACE:${PROTO_HEADER_PATH_I}/xrpc-test.pb.h>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/server/x-server.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/client/x-client.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/src/proto/math.pb.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/src/proto/math.grpc.pb.cc

        ${CMAKE_CURRENT_SOURCE_DIR}/src/proto/math.proto
#        ${PROTO_SOURCES}
)

protobuf_generate(
  TARGET ${PROJECT_NAME}
  LANGUAGE grpc
  GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
  PLUGIN protoc-gen-grpc=$<TARGET_FILE:gRPC::grpc_cpp_plugin>
  PROTOC_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/
)

protobuf_generate(
        TARGET ${PROJECT_NAME}
        LANGUAGE cpp
        GENERATE_EXTENSIONS .pb.h .pb.cc
        PLUGIN protoc-gen-grpc=$<TARGET_FILE:gRPC::grpc_cpp_plugin>
        PROTOC_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/
)


target_link_libraries(${PROJECT_NAME}
        PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

if (Protobuf_VERSION VERSION_GREATER_EQUAL 4)
    target_link_libraries (${PROJECT_NAME}
        PUBLIC
            absl::log_internal_check_op
    )
endif ()

target_include_directories(${PROJECT_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)

set(PROJECT_NAMESPACE xrpc::)
message(STATUS "[${PROJECT_NAME}] installing ${PROJECT_NAME} in namespace ${PROJECT_NAMESPACE}")
include(GNUInstallDirs)
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)
message(STATUS "[${PROJECT_NAME}] installing in prefix: ${CMAKE_INSTALL_PREFIX}")

set(PROJECT_CONFIG_FILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config.cmake.in")
set(PROJECT_CONFIG_FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake")
set(CONFIG_TARGETS_FILE "${PROJECT_NAME}-config-targets.cmake")
set(CONFIG_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake")
set(INSTALL_EXPORT_DESTINATION_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/xrpc> $<INSTALL_INTERFACE:include/xrpc> ;'
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h"
)
export(TARGETS ${PROJECT_NAME} NAMESPACE ${PROJECT_NAMESPACE} FILE "${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_TARGETS_FILE}")
install(EXPORT ${PROJECT_NAME}
        DESTINATION ${INSTALL_EXPORT_DESTINATION_DIR}
        NAMESPACE ${PROJECT_NAMESPACE}
        FILE ${CONFIG_TARGETS_FILE}
)
configure_package_config_file(${PROJECT_CONFIG_FILE_IN} ${PROJECT_CONFIG_FILE} INSTALL_DESTINATION ${INSTALL_EXPORT_DESTINATION_DIR})
write_basic_package_version_file(${CONFIG_VERSION_FILE} COMPATIBILITY AnyNewerVersion)
install(FILES ${PROJECT_CONFIG_FILE} ${CONFIG_VERSION_FILE} DESTINATION ${INSTALL_EXPORT_DESTINATION_DIR})

message(STATUS "[${PROJECT_NAME}] configuring ${PROJECT_NAME} done!")

add_subdirectory(bin)