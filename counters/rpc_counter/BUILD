cc_binary(
    name = "server",
    srcs = ["main.cc"],
    deps = [
        "//protos:counter_cc_grpc",
        "//counters/shared:main",
        "@com_github_grpc_grpc//:grpc++",
    ]
)