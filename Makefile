# Compilador e flags
CC = g++
CFLAGS = -Wall -Wextra -std=c++17

# Diretórios
SRC_DIR = src
INC_DIR = include
EXEC = servidor.out

# Fontes
SRCS = $(SRC_DIR)/aluno.cpp $(SRC_DIR)/main.cpp
HDRS = $(INC_DIR)/aluno.hpp $(INC_DIR)httplib.h

# Regras
all: build

build:
	$(CC) $(CFLAGS) -I$(INC_DIR) $(SRCS) -o $(EXEC) -lpthread

clean:
	rm -f $(EXEC)

.PHONY: all build clean
