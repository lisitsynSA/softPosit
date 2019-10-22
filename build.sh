#! /bin/bash

echo "[BUILD LLVM + SOFT FP + SOFT POSIT]"
mkdir BUILD
cd BUILD
cmake ../llvm/ -DCMAKE_BUILD_TYPE="Release" -DCMAKE_INSTALL_PREFIX="../SOFT_POSIT" #-DCMAKE_VERBOSE_MAKEFILE=1
make -j12 && make install
