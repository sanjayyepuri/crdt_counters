#pragma once

#include <utility>
#include <grpcpp/grpcpp.h>

namespace crdt_counter
{
    template<class T,
        typename std::enable_if<
            std::is_base_of<grpc::Service, T>::value>::type* = nullptr>
    void RunServer
        ()
    {
        std::string address = "0.0.0.0";
        std::string port = "50051";
        std::string server_address = address + ":" + port;
        T service;

        grpc::ServerBuilder builder;
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

        builder.RegisterService(&service);
        std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
        std::cout << "Server listening on: " << server_address << std::endl;

        server->Wait();
    }
}