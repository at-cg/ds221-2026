# DS221 Assignment 1
# Compiler available on teaching cluster: GCC 8.5.0 / C++14

CXX      := g++
CXXFLAGS := -std=c++14 -O2

TARGET := ds221_exe

SAMPLE_DIR := sample_test

Q1_INPUT  := $(SAMPLE_DIR)/Question_1/input.txt
Q1_OUTPUT := $(SAMPLE_DIR)/Question_1/output.txt

Q2_INPUT  := $(SAMPLE_DIR)/Question_2/input.txt
Q2_OUTPUT := $(SAMPLE_DIR)/Question_2/output.txt

Q3_INPUT  := $(SAMPLE_DIR)/Question_3/input.txt
Q3_OUTPUT := $(SAMPLE_DIR)/Question_3/output.txt

SOURCES := main.cpp
HEADERS := user_code.h file_reader.h file_writer.h

.PHONY: all clean run sample help

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@ $(LDFLAGS)

# Run using the provided sample inputs
test: $(TARGET)
	./$(TARGET) \
		$(Q1_INPUT) $(Q1_OUTPUT) \
		$(Q2_INPUT) $(Q2_OUTPUT) \
		$(Q3_INPUT) $(Q3_OUTPUT)

# Build and run sample tests
run:    test
	@echo
	@echo "===== Sample outputs ====="
	@echo "Question 1:"
	@cat $(Q1_OUTPUT)
	@echo "Question 2:"
	@cat $(Q2_OUTPUT)
	@echo "Question 3:"
	@cat $(Q3_OUTPUT)

# Remove generated executable
clean:
	rm -f $(TARGET)

help:
	@echo "Available targets:"
	@echo "  make         Build the program"
	@echo "  make run     Build, run, and display sample outputs"
	@echo "  make clean   Remove generated files"
	@echo "  make help    Show this help message"
