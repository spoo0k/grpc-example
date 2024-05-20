//
// Created by user on 20.05.24.
//

#pragma once
#include <experimental/propagate_const>
#include <functional>
#include <memory>
#include <optional>
#include <utility>


namespace xrpc
{
  namespace math  { class MathRequest; }

  class XServer
  {
    public:
      explicit XServer(std::function<std::optional<float>(const math::MathRequest&)>  do_math);
      auto run(const std::string& address, uint16_t port) -> void;
    private:
      class Impl;
      std::experimental::propagate_const<std::unique_ptr<Impl>> m_impl;
  };
}
