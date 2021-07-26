# HyperProtoBench

Version: 0.0.1-alpha

HyperProtoBench is a suite of six synthetic benchmarks for Protocol Buffers
serialization and deserialization. Each benchmark processes messages that are
representative of those used in a service at Google. This suite is not intended
to be static; we expect HyperProtoBench to evolve over time.

Further details will be made available in an upcoming paper at the 54th IEEE/ACM
International Symposium on Microarchitecture (MICRO 2021).

This is not an officially supported Google product.

## Contents

Each benchmark directory (``bench0`` - ``bench5``) includes four files:

* ``benchmark.cc``: Top-level driver.
* ``benchmark.inc``: Workload-specific generated protobuf operations.
* ``benchmark.proto``: Protobuf message definitions for the benchmark.
* ``Makefile``: Basic build flow.

## How to Use:

To build and run a benchmark:

    cd bench0
    [ update Makefile to point to your toolchain and protobufs install ]
    make
    ./benchmark

