CXX := g++
CXX_FLAGS := -std=c++17

BIN := bin
SRC := src

EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

clean:
	-rm $(BIN)/*