.PHONY: build-kernel

build-kernel:
	cd kernel && make
	riscv64-unknown-elf-ld -T kernel/linker.ld -nostdlib boot.o kernel/obj/*.o  -o kernel/bin/nposkrnl.exe

build-loader:
	cd boot && make

all:
	@if [ ! -d kernel/bin ]; then \
		mkdir -p kernel/bin; \
	fi
	make build-loader
	make build-kernel


clean:
	cd kernel && make clean
	cd boot && make clean
	rm -rf kernel/bin
run:
	make all
	qemu-system-riscv64 -machine virt -bios none -kernel kernel/bin/nposkrnl.exe -device virtio-gpu -display gtk -serial mon:stdio 