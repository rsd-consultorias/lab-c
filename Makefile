# Nome do executável
TARGET = rsdtools-v1.0.0

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Iinclude -framework Cocoa

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos fonte e objetos
SRC_C_FILES = $(wildcard $(SRC_DIR)/*.c)
SRC_M_FILES = $(wildcard $(SRC_DIR)/*.m)
OBJ_C_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_C_FILES))
OBJ_M_FILES = $(patsubst $(SRC_DIR)/%.m, $(OBJ_DIR)/%.o, $(SRC_M_FILES))
OBJ_FILES = $(OBJ_C_FILES) $(OBJ_M_FILES)

# Regra padrão
all: $(BIN_DIR)/$(TARGET)

# Regra para compilar o executável
$(BIN_DIR)/$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

# Regra para compilar arquivos .m em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.m
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

# Limpar arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# PHONY targets
.PHONY: all clean
