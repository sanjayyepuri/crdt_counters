workspace(name = "crdt_counters")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# https://rules-proto-grpc.aliddell.com/en/latest/example.html
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_proto_grpc",
    sha256 = "7954abbb6898830cd10ac9714fbcacf092299fda00ed2baf781172f545120419",
    strip_prefix = "rules_proto_grpc-3.1.1",
    urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/3.1.1.tar.gz"],
)

load("@rules_proto_grpc//:repositories.bzl", "rules_proto_grpc_toolchains", "rules_proto_grpc_repos")
rules_proto_grpc_toolchains()
rules_proto_grpc_repos()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

load("@rules_proto_grpc//cpp:repositories.bzl", "cpp_repos")
cpp_repos()

load("@rules_proto_grpc//python:repositories.bzl", "python_repos")
python_repos()

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

# Third party libraries
load("@rules_python//python:pip.bzl", "pip_install")

pip_install(
    name = "rules_proto_grpc_py3_deps",
    requirements = "@rules_proto_grpc//python:requirements.txt",
)

pip_install(
    name = "py_deps",
    requirements = "//:requirements.txt",
)

## add cxxopts to workspace
http_archive(
    name = "cxxopts",
    urls = ["https://github.com/jarro2783/cxxopts/archive/refs/tags/v2.2.1.tar.gz"],
    sha256 = "984aa3c8917d649b14d7f6277104ce38dd142ce378a9198ec926f03302399681",
    strip_prefix = "cxxopts-2.2.1",
    build_file_content = """
cc_library(
    name="cxxopts",
    srcs=glob(["src/example.cpp"]),
    hdrs=glob(["include/cxxopts.hpp"]),
    copts = ["-Iexternal/cxxopts/include"],
    visibility = ["//visibility:public"],
)
"""
)