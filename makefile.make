CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

SRC_DIR := src
BUILD_DIR := build
LIB_DIR := lib

LIB_NAME := my_lib
LIB_EXT := a
ifdef SystemRoot
    LIB_EXT := lib
endif
LIB := $(LIB_DIR)/lib$(LIB_NAME).$(LIB_EXT)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJ_FILES)
	mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/functions.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)
