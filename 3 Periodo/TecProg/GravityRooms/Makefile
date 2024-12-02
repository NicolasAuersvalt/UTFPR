# Caminho para a instalação da SFML no seu sistema
SFML_DIR = C:/SFML

# Caminho para o compilador MinGW
CXX = g++

# Flags de compilação
CXXFLAGS = -Isrc/include

# Flags de linkagem
LDFLAGS = -L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

# Nome do arquivo de saída
OUT = main

# Alvo padrão
all: compile link

# Passo de compilação
compile:
	$(CXX) $(CXXFLAGS) -c main.cpp

# Passo de linkagem
link:
	$(CXX) main.o -o $(OUT) $(LDFLAGS)
