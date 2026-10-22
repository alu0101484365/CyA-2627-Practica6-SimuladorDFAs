# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Asignatura: Computabilidad y Algoritmia
# Práctica 6: Simulador de DFAs

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g
SRC_DIR = .
OBJ_DIR = obj

TARGET = p06_DFA_simulator

SRCS = $(wildcard $(SRC_DIR)/*.cc)
OBJS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean