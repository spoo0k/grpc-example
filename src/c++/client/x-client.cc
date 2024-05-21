//
// Created by user on 20.05.24.
//

#include <grpcpp/grpcpp.h>
#include <xrpc-test/client/x-client.h>


class xrpc::XClient::Impl
{
  public:
    explicit Impl(std::shared_ptr<grpc::Channel> channel);
    std::unique_ptr<xrpc::math::MathService::Stub> m_stub;
};

xrpc::XClient::Impl::Impl(std::shared_ptr<grpc::Channel> channel)
  : m_stub(xrpc::math::MathService::NewStub(channel))
{}

xrpc::XClient::XClient(const std::string& address,
                       const uint16_t port)
  : m_impl(std::make_unique<Impl>(grpc::CreateChannel(address + ":" + std::to_string(port),
                                                      grpc::InsecureChannelCredentials())))
{}

xrpc::XClient::~XClient() = default;

auto xrpc::XClient::math_request(math::MathRequest request) -> void
{
  math::MathResponse response;
  grpc::ClientContext context;
  auto  status = m_impl->m_stub->CalculateMath(&context, request, &response);
  if (status.ok()) {
    if (response.has_result()) {
      std::cout << "Result: " << response.result() << std::endl;
    }
    else
    {
      std::cout << "Result not found divided by zero" << std::endl;
    }
  }
}
