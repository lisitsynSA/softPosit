# softPosit
Software emulation of IEEE 754 and Posit standarts

Prepare LLVM (already done):
[LLVM]
	git clone https://github.com/llvm-mirror/llvm.git
	cd llvm
	git checkout release_90
[CLANG]
	cd tools
	git clone https://github.com/llvm-mirror/clang.git
	cd clang
	git checkout release_90
[COMPILER-RT]
	cd ../../projects
	git clone https://github.com/llvm-mirror/compiler-rt.git
	cd compiler-rt
	git checkout release_90
