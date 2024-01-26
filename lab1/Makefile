# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 

# Targets
PROGS =  hello ltest encode decode test_coding print_argv

all: $(PROGS)

codetest: test_coding
	./test_coding

listtest: ltest
	./ltest

# Targets rely on implicit rules for compiling and linking
ltest: ltest.o list.o
test_coding: test_coding.o coding.o
encode: encode.o coding.o
decode: decode.o coding.o
print_argv: print_argv.o

# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
