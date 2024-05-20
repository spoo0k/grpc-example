//
// Created by user on 20.05.24.
//

#include  <iostream>

#include <xrpc/proto/math.pb.h>
#include <xrpc/client/x-client.h>

int main() {
  xrpc::XClient client("127.0.0.1", 50051);
  xrpc::math::MathRequest request;
  request.set_operation(xrpc::math::MathOperation::Add);
  request.mutable_arguments()->set_lhs(1.0);
  request.mutable_arguments()->set_rhs(2.0);
 client.math_request(request);
 return 0;
}