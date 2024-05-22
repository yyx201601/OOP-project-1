# Specify compiler
CXX = g++

# Compile options
CXXFLAGS = -std=c++11 -Wall

# List of source files
SRCS = Animal.cpp Corn.cpp Wheat.cpp Farm.cpp Crop.cpp Inventory.cpp Player.cpp main.cpp

# List of target files
OBJS = $(SRCS:.cpp=.o)

# Final generated executable
TARGET = farm_game

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generate rules for each target file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up the generated files
clean:
	rm -f $(OBJS) $(TARGET)
