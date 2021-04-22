#include <utility>
#include <grpcpp/grpcpp.h>
#include <cxxopts.hpp>

#include "counter.h"

namespace crdt
{
    void ParseArgs(int argc, char **argv, ServerArgs &args)
    {
        cxxopts::Options opts ("Counter", "Server that hosts a local counter");
        opts.add_options()
            ("h,address", "Host name",
                cxxopts::value<std::string>()->default_value("0.0.0.0"))
            ("p,port", "Port",
                cxxopts::value<std::string>()->default_value("50051"))
            ;
        auto result = opts.parse(argc, argv);

        args.address = result["address"].as<std::string>();
        args.port = result["port"].as<std::string>();
    }
}