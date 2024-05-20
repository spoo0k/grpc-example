//
// Created by user on 20.05.24.
//

#pragma once

#include <string>
#include <cstdint>
#include <functional>
#include <memory>
#include <experimental/propagate_const>

namespace xrpc {
  namespace math  { class MathRequest; }

  class XClient
  {
    public:
      explicit XClient(const std::string &address, uint16_t port);
      auto math_request(math::MathRequest) -> void;

    private:
      class Impl;
      std::experimental::propagate_const<std::unique_ptr<Impl>> m_impl;

  };
}