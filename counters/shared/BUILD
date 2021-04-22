cc_library(
    name = "main",
    srcs = ["counter.cc"],
    hdrs = ["counter.h"],
    deps = [
        "@cxxopts//:cxxopts",
        "@com_github_grpc_grpc//:grpc++",
    ],
    copts = ["-Iexternal/cxxopts/include"],
    visibility = ["//visibility:public"],
)