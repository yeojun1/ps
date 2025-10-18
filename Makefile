CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -lm -std=gnu++17

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $@.cpp

.PHONY: clean
clean:
	rm -rf .vscode
	rm -f $(wildcard *.out)
	clear