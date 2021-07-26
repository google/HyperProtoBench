

CXX=g++
STRIP=strip
CXXFLAGS=-O3 -std=c++11 -fno-omit-frame-pointer -static
PROTOINCLUDES=~/protobuf/src
INCLUDES = -I $(PROTOINCLUDES)
PROTOLIB=-L $(PROTOINCLUDES)/.libs -l:libprotobuf.a
OTHERLIBS=-lpthread
PROTOCDIR=~/protobuf/src/protoc

objects = benchmark.o benchmark.pb.o

all: benchmark

benchmark.pb.cc: benchmark.proto
	$(PROTOCDIR) $< --cpp_out=.

%.o : %.cc benchmark.pb.cc benchmark.inc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<

benchmark: $(objects)
	$(CXX) $(CXXFLAGS)  $(objects) -o $@ $(PROTOLIB) $(OTHERLIBS)
	$(STRIP) $@

clean:
	rm benchmark $(objects) benchmark.pb.cc benchmark.pb.h
