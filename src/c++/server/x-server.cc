//
// Created by user on 20.05.24.
//

#include <xrpc-test/server/x-server.h>
#include <grpcpp/grpcpp.h>


class xrpc::XServer::Impl : public math::MathService::Service
{
  public:
    explicit Impl(std::function<std::optional<float>(const math::MathRequest&)> do_math);
    auto CalculateMath(::grpc::ServerContext* context, const xrpc::math::MathRequest* request,
                       xrpc::math::MathResponse* response) -> grpc::Status override;
  private:
    std::function<std::optional<float>(const math::MathRequest&)> m_callback;
};

xrpc::XServer::Impl::Impl(std::function<std::optional<float>(const math::MathRequest&)> do_math)
  : m_callback(std::move(do_math))
{}

grpc::Status xrpc::XServer::Impl::CalculateMath(grpc::ServerContext* context, const xrpc::math::MathRequest* request,
  xrpc::math::MathResponse* response)
{
  if (const auto result = m_callback(*request)) {
    response->set_result(result.value());
  }
  return grpc::Status::OK;
}


xrpc::XServer::XServer(std::function<std::optional<float>(const math::MathRequest&)> do_math)
  : m_impl(std::make_unique<Impl>(std::move(do_math)))
{}

xrpc::XServer::~XServer() = default;

auto xrpc::XServer::run(const std::string& address, uint16_t port) -> void
{
  const auto target_addr = address + ":" + std::to_string(port);
  grpc::ServerBuilder builder;
  builder.AddListeningPort(target_addr, grpc::InsecureServerCredentials());
  builder.RegisterService(m_impl.get());
  auto server = builder.BuildAndStart();
  server->Wait();
  server->Shutdown();
}
