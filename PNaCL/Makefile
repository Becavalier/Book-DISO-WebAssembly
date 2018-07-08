#
# 获取 Pepper SDK 相关的工具链和头文件目录；
#
THIS_MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))
NACL_SDK_ROOT ?= $(abspath $(dir $(THIS_MAKEFILE))../../pepper_49)

# 一些编译器符号；
WARNINGS := -Wno-long-long -Wall -Wswitch-enum -pedantic -Werror
CXXFLAGS := -pthread -std=gnu++98 $(WARNINGS)

#
# Compute tool paths
#
GETOS := python $(NACL_SDK_ROOT)/tools/getos.py
OSHELPERS = python $(NACL_SDK_ROOT)/tools/oshelpers.py
OSNAME := $(shell $(GETOS))
RM := $(OSHELPERS) rm

PNACL_TC_PATH := $(abspath $(NACL_SDK_ROOT)/toolchain/$(OSNAME)_pnacl)
PNACL_CXX := $(PNACL_TC_PATH)/bin/pnacl-clang++
PNACL_FINALIZE := $(PNACL_TC_PATH)/bin/pnacl-finalize
CXXFLAGS := -I$(NACL_SDK_ROOT)/include
LDFLAGS := -L$(NACL_SDK_ROOT)/lib/pnacl/Release -lppapi_cpp -lppapi

# 设置编译目标；
all: pnacl_fibonacci.pexe

clean:
	$(RM) pnacl_fibonacci.pexe pnacl_fibonacci.bc

pnacl_fibonacci.bc: pnacl_fibonacci.cc
	$(PNACL_CXX) -o $@ $< -O2 $(CXXFLAGS) $(LDFLAGS)

pnacl_fibonacci.pexe: pnacl_fibonacci.bc
	$(PNACL_FINALIZE) -o $@ $<
