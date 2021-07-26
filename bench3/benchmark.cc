// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <algorithm>
#include <array>
#include <string>
#include <iostream>
#include <chrono>

using std::string;

#include "benchmark.pb.h"

namespace hyperprotobench {

const size_t kReceiverSize = 65536;

struct Receiver {
  std::array<const std::string*, kReceiverSize> string_r;
  size_t string_i;
  std::array<bool, kReceiverSize> bool_r;
  size_t bool_i;
  std::array<double, kReceiverSize> double_r;
  size_t double_i;
  std::array<float, kReceiverSize> float_r;
  size_t float_i;
  std::array<int32_t, kReceiverSize> int32_r;
  size_t int32_i;
  std::array<int64_t, kReceiverSize> int64_r;
  size_t int64_i;
  std::array<uint32_t, kReceiverSize> uint32_r;
  size_t uint32_i;
  std::array<uint64_t, kReceiverSize> uint64_r;
  size_t uint64_i;
};

struct Receiver receiver;

inline void ReceiveString(const std::string& val) {
  receiver.string_i = (receiver.string_i + 1) % kReceiverSize;
  receiver.string_r[receiver.string_i] = &val;
}

inline void ReceiveBool(const bool& val) {
  receiver.bool_i = (receiver.bool_i + 1) % kReceiverSize;
  receiver.bool_r[receiver.bool_i] = val;
}

inline void ReceiveDouble(const double& val) {
  receiver.double_i = (receiver.double_i + 1) % kReceiverSize;
  receiver.double_r[receiver.double_i] = val;
}

inline void ReceiveFloat(const float& val) {
  receiver.float_i = (receiver.float_i + 1) % kReceiverSize;
  receiver.float_r[receiver.float_i] = val;
}

inline void ReceiveInt32(const int32_t& val) {
  receiver.int32_i = (receiver.int32_i + 1) % kReceiverSize;
  receiver.int32_r[receiver.int32_i] = val;
}

inline void ReceiveInt64(const int64_t& val) {
  receiver.int64_i = (receiver.int64_i + 1) % kReceiverSize;
  receiver.int64_r[receiver.int64_i] = val;
}

inline void ReceiveUint32(const uint32_t& val) {
  receiver.uint32_i = (receiver.uint32_i + 1) % kReceiverSize;
  receiver.uint32_r[receiver.uint32_i] = val;
}

inline void ReceiveUint64(const uint64_t& val) {
  receiver.uint64_i = (receiver.uint64_i + 1) % kReceiverSize;
  receiver.uint64_r[receiver.uint64_i] = val;
}

// Include the generated benchmark code which defines a BenchmarkIteration()
// entry point.
#include "benchmark.inc"

}  // namespace hyperprotobench

// Number of protobuf instances to instantiate.
#define WORKING_SET_SIZE 1

int main(int argc, char** argv) {
  int iters = 1;
  google::protobuf::Arena arena;
  google::protobuf::Arena* arena_p = &arena;

  std::chrono::time_point<std::chrono::steady_clock> start, end;

  start = std::chrono::steady_clock::now();
  for (int i = 0; i < iters; i++) {
    hyperprotobench::BenchmarkIteration(WORKING_SET_SIZE, arena_p);
  }
  end = std::chrono::steady_clock::now();

  std::chrono::duration<double> elapsed = end - start;
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() / iters << " ns per iter. iterations: " << iters << "\n";

  return 0;
}
