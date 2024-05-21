//
// Created by user on 20.05.24.
//

#include <iostream>
#include <thread>
#include <xrpc-test/server/x-server.h>
#include <xrpc-test/protobufs/math.grpc.pb.h>


int main()
{
  xrpc::XServer server([](const xrpc::math::MathRequest& request) -> std::optional<float>
  {
    if (request.operation() == xrpc::math::MathOperation::Add)
    {
      return request.arguments().lhs() + request.arguments().rhs();
    }
    else if (request.operation() == xrpc::math::MathOperation::Subtract)
    {
      return request.arguments().lhs() - request.arguments().rhs();
    }
    else if (request.operation() == xrpc::math::MathOperation::Multiply)
    {
      return request.arguments().lhs() * request.arguments().rhs();
    }
    else if (request.operation() == xrpc::math::MathOperation::Divide)
    {
      if (request.arguments().rhs() == 0)
      {
        return std::nullopt;
      }
      return request.arguments().lhs() / request.arguments().rhs();
    }
    return std::nullopt;
  });

  std::thread t([&server]()
  {
    server.run("0.0.0.0", 50051);
  });
  t.detach();

  while (true)
  {
    std::cout << "Hello, World!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  // server.run("0.0.0.0", 50051);
  // std::cout << "Hello, World!" << std::endl;
  return 0;
}
