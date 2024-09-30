SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

CC = riscv64-unknown-elf-g++
CFLAGS = -ffreestanding

all: $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf bin

