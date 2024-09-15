.PHONY: build-kernel

build-kernel:
	cd kernel && make

build-loader:
	cd boot && make

all:
	@if [ ! -d bin ]; then \
		mkdir -p bin; \
	fi
	make build-loader
	make build-kernel
	riscv64-unknown-elf-ld -T linker.ld -nostdlib boot.o obj/*.o  -o bin/nposkrnl.exe


clean:
	cd kernel && make clean
	cd boot && make clean
	rm -rf bin
run:
	make all
	qemu-system-riscv64 -machine virt -bios none -kernel bin/nposkrnl.exe -device virtio-gpu -display sdl -serial mon:stdio 