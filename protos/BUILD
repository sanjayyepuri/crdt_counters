load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library")
load("@rules_proto_grpc//python:defs.bzl", "python_grpc_library")

proto_library(
    name = "counter_proto",
    srcs = [
        "sync_counter.proto",
        "messages.proto"
    ],
)

## Targets for cpp
cpp_proto_library(
    name = "counter_cc_proto",
    protos = ["//protos:counter_proto"]
)

cpp_grpc_library(
    name = "counter_cc_grpc",
    protos = ["//protos:counter_proto"],
    deps = ["//protos:counter_cc_proto"],
    visibility = ["//visibility:public"]
)

# Targets for py
python_grpc_library(
    name = "counter_py_grpc",
    protos = ["//protos:counter_proto"],
    visibility = ["//visibility:public"]
)