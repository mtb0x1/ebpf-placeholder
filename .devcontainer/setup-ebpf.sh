#!/bin/bash
sudo apt-get update && sudo apt-get install -y \
  clang llvm libelf-dev gcc make iproute2 iputils-ping \
  libbpf-dev linux-headers-$(uname -r) \
  bpfcc-tools python3-bpfcc \
  cmake \
  linux-tools-common linux-tools-generic linux-tools-$(uname -r) 