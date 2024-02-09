# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Werror -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 

# Targets
PROGS = load_words spell

all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
load_words: load_words.o trigrams.o

spell: spell.o dictionary.o word.o trigrams.o

words.txt:
	./load_words < /usr/share/dict/words > $@

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
