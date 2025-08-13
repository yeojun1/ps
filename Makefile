CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@.out $@.cpp

.PHONY: clean
clean:
	rm -f $(wildcard *.out)
