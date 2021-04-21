load("@py_deps//:requirements.bzl", "requirement")

py_binary(
    name = "counter_client",
    main = "client.py",
    srcs = ["client.py"],
    python_version = "PY3",
    deps = [
        requirement("grpcio-tools"),
        "//protos:counter_py_grpc"
    ]
)