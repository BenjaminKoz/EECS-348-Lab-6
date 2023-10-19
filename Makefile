CXX = g++
TARGET = matrix_operations
SRCS = matrix_operations.cpp
all: $(TARGET)
$(TARGET): $(SRCS)
	$(CXX) -o $@ $(SRCS)
clean:
	rm -f $(TARGET)