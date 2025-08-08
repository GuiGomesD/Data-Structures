CXX = g++
CXXFLAGS = -Wall -std=c++11
INCLUDES = -Iinclude
SRC = src/fila.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = fila

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC)
