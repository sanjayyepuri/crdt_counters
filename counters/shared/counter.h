#pragma once

#include <inttypes.h>
#include <atomic>
#include <grpcpp/grpcpp.h>

namespace crdt
{
    class Counter
    {
    public:
        virtual void Add() = 0;
        virtual void Subtract() = 0;
        virtual int64_t Get() = 0;
    };

    class LocalCounter : Counter
    {
    public:
        LocalCounter() : value_(0) {}
        void Add() override
        {
            value_.fetch_add(1, std::memory_order_seq_cst);
        }

        void Subtract() override
        {
            value_.fetch_add(-1, std::memory_order_seq_cst);
        }

        int64_t Get() override
        {
            return value_.load(std::memory_order_seq_cst);
        }

    private:
        std::atomic<int64_t> value_;
    };

    struct ServerArgs
    {
        std::string address;
        std::string port;
    };

    void ParseArgs(int argc, char **argv, ServerArgs &args);

    template <class T,
              typename std::enable_if<
                  std::is_base_of<grpc::Service, T>::value>::type * = nullptr>
    void RunServer(ServerArgs &args)
    {
        std::string server_address = args.address + ":" + args.port;
        T service;

        grpc::ServerBuilder builder;
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

        builder.RegisterService(&service);
        std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
        std::cout << "Server listening on: " << server_address << std::endl;

        server->Wait();
    }
} // crdt_counter