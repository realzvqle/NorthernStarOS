.PHONY: build-kernel

build-kernel:
	cd kernel && make



all:
	make build-kernel


clean:
	cd kernel && make clean
run:
	make all
	qemu-system-riscv64 -m 2G -machine virt -bios none -kernel kernel/bin/kernel.exe -device ramfb -device virtio-keyboard-pci -display sdl -serial mon:stdio 

run-debug:
	make all
	qemu-system-riscv64 -m 2G -machine virt -bios none -kernel kernel/bin/kernel.exe -device ramfb -device virtio-keyboard-pci -display sdl -serial mon:stdio -d int,cpu_reset

run-debug-gdb:
	make all
	qemu-system-riscv64 -m 2G -machine virt -bios none -kernel kernel/bin/kernel.exe -device ramfb -device virtio-keyboard-pci -display sdl -serial mon:stdio -d int,cpu_reset -s -S