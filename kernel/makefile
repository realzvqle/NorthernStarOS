SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LINKER_SCRIPT = linker.ld
BOOT_SRC = boot/src/entry.S  
BOOT_OBJ = $(OBJ_DIR)/boot.o
SRC_FILES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_FILES:.cpp=.o))

CC = riscv64-unknown-elf-g++
LD = riscv64-unknown-elf-ld
CFLAGS = -ffreestanding



all: $(BIN_DIR)/kernel.exe

$(BIN_DIR)/kernel.exe: $(BOOT_OBJ) $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(LD) -T $(LINKER_SCRIPT) -nostdlib $(shell find $(OBJ_DIR) -name '*.o') -o $(BIN_DIR)/kernel.exe


$(BOOT_OBJ): $(BOOT_SRC)
	@mkdir -p $(OBJ_DIR)
	riscv64-unknown-elf-as $(BOOT_SRC) -o $(BOOT_OBJ)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
