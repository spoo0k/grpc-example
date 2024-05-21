//
// Created by user on 20.05.24.
//

#pragma once

#include <string>
#include <cstdint>
#include <functional>
#include <memory>
#include <experimental/propagate_const>
#include <xrpc-test/protobufs/math.grpc.pb.h>

namespace xrpc {


  class XClient
  {
    public:
      explicit XClient(const std::string &address, uint16_t port);
      ~XClient();
      auto math_request(math::MathRequest) -> void;

    private:
      class Impl;
      std::experimental::propagate_const<std::unique_ptr<Impl>> m_impl;

  };
}