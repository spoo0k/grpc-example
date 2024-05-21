//
// Created by user on 20.05.24.
//

#include  <iostream>
#include <thread>
#include <xrpc-test/client/x-client.h>
#include <xrpc-test/protobufs/math.grpc.pb.h>

int main() {
  xrpc::XClient client("127.0.0.1", 50051);
  xrpc::math::MathRequest request;
  request.set_operation(xrpc::math::MathOperation::Multiply);
  request.mutable_arguments()->set_lhs(5.0);
  request.mutable_arguments()->set_rhs(10.0);
  client.math_request(request);
 return 0;
}