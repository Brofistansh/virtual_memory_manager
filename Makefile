CXX = clang++
CXXFLAGS = -std=c++20 -O2 -pthread
INCLUDES = -Iinclude
SRC = src/main.cpp src/FIFOReplacement.cpp
OUT = build/vm_manager

all:
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDES) -o $(OUT)

clean:
	rm -rf build
