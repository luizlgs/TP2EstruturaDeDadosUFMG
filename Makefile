# ------------------------------------------------
# Configurações do Compilador
# ------------------------------------------------
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# ------------------------------------------------
# Diretórios do Projeto
# ------------------------------------------------
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Nome do executável gerado
TARGET = $(BIN_DIR)/redesocial

# ------------------------------------------------
# Arquivos Fonte e Objetos
# ------------------------------------------------
# Pega todos os arquivos .cpp dentro da pasta src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Substitui o caminho 'src/arquivo.cpp' por 'obj/arquivo.o'
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# ------------------------------------------------
# Regras de Compilação
# ------------------------------------------------

# Regra principal solicitada (roda com 'make all' ou apenas 'make')
all: $(TARGET)

# Regra para gerar o executável final na pasta bin/
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build completo! $@"

# Regra para gerar os arquivos .o na pasta obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compilado: $<"

# Regra para limpar os arquivos gerados (roda com 'make clean')
clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
	@echo "Arquivos compilados removidos (pastas mantidas)."

# Declara que 'all' e 'clean' não são arquivos físicos
.PHONY: all clean