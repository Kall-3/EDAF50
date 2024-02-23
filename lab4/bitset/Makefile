CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 

PROGS = simplebitsettest bitsettest1 bitsettest2

all: $(PROGS)

simplebitsettest: simplebitsettest.o simplebitset.o

bitsettest1: bitsettest1.o bitset.o bitreference.o

bitsettest2: bitsettest2.o bitset.o bitreference.o

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
