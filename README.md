# softPosit
Software emulation of IEEE 754 and Posit standarts

# Prepare LLVM (already done):
	[LLVM]
	git clone https://github.com/llvm-mirror/llvm.git
	cd llvm
	git checkout release_90
	rm .git* -rf

	[CLANG]
	cd tools
	git clone https://github.com/llvm-mirror/clang.git
	cd clang
	git checkout release_90
	rm .git* -rf

	[COMPILER-RT]
	cd ../../projects
	git clone https://github.com/llvm-mirror/compiler-rt.git
	cd compiler-rt
	git checkout release_90
	rm .git* -rf

# Prepare build system:
	sudo apt-get install build-essential zlib1g-dev python cmake

# Building:
	./build.sh
	Two folders will be created: BUILD and SOFT_POSIT
	Compiler will be in SOFT_POSIT/bin

# Commit message
Template: [TYPE] Description

TYPES: INFR; LLVM; IEEE_754; POSIT; TESTS
