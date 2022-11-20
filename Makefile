CXX := g++
CXX_FLAGS := -std=c++17

BIN := bin
SRC := src

EXECUTABLE := main
INCLUDE := include


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE) < ./input.txt
	./lib/quabs --partial-assignment ./test.qcir

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@

clean:
	-rm $(BIN)/*