#include <iostream>

#include <grpcpp/grpcpp.h>

#include "protos/messages.grpc.pb.h"
#include "protos/sync_counter.grpc.pb.h"

#include "counters/counter.h"
#include "counters/server.h"

;
using grpc::Status;
using grpc::ServerContext;

using crdt_counter::Empty;
using crdt_counter::GetResponse;
using crdt_counter::SyncCounter;

using crdt_counter::Counter;
using crdt_counter::LocalCounter;

class SyncCounterService final : public SyncCounter::Service
{

public:
    Status Add(ServerContext *ctx,
        const Empty *req, Empty *res) override
    {
        counter_.Add();
        return Status::OK;
    }

    Status Subtract(ServerContext *ctx,
        const Empty *req, Empty* res) override
    {
        counter_.Subtract();
        return Status::OK;
    }

    Status Get(ServerContext *ctx,
        const Empty *req, GetResponse *res) override
    {
        res->set_value(counter_.Get());
        return Status::OK;
    }

private:
    LocalCounter counter_;
};

int main()
{
    crdt_counter::RunServer<SyncCounterService>();
    return 0;
}