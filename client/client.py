import logging
import asyncio
import grpc

import protos.messages_pb2 as messages
import protos.sync_counter_pb2_grpc as sync_counter

def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = sync_counter.SyncCounterStub(channel)
        response = stub.Add(messages.Empty())
        response = stub.Get(messages.Empty())
    print("Greeter client received: " + str(response.value))


if __name__ == '__main__':
    logging.basicConfig()
    run()