# executable name
EXE = app

# Compiler
CC = gcc
CXX = g++
LD = g++

# Misc
CPPUTEST_HOME=../tools/cpputest

# Flags
CFLAGS =

CXXFLAGS = 

CPPFLAGS =
CPPFLAGS += -I$(CPPUTEST_HOME)/include

LDLIBS = -L$(CPPUTEST_HOME)/cpputest_build/lib -lCppUTest -lCppUTestExt

# dependency-generation flags
#DEPFLAGS = -MMD -MP

# Build
BIN = bin
OBJ = obj
SRC = ../TL_MAIN_MCU/App
TST = .

# C Source files
C_SRC = \
$(SRC)/thermistor.c 

# CPP Source files
CPP_SRC = \
$(TST)/AllTests.cpp \
$(TST)/ThermistorTest.cpp \

# List of objects
C_OBJ = $(C_SRC:.c=.o)
CPP_OBJ = $(CPP_SRC:.cpp=.o)


# compile C source
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@

# compile C++ source
COMPILE.cxx = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# link objects
LINK.o = $(LD) $(LDFLAGS) $(LDLIBS) $(C_OBJ) $(CPP_OBJ) -o $@

.DEFAULT_GOAL = all

.PHONY: all
all: $(BIN)/$(EXE)
	./$(BIN)/$(EXE)

$(BIN)/$(EXE): $(C_OBJ) $(CPP_OBJ)
	$(LINK.o)
	$(RM) $(C_OBJ)
	$(RM) $(CPP_OBJ)

.c.o: 
	$(COMPILE.c)

.cpp.o: 
	$(COMPILE.cxx) 

# force rebuild
.PHONY: remake
remake:	clean $(BIN)/$(EXE)

# execute the program
.PHONY: run
run: $(BIN)/$(EXE)
	./$(BIN)/$(EXE)

# remove previous build and objects
.PHONY: clean
clean:
	$(RM) $(C_OBJ)
	$(RM) $(CPP_OBJ)
	$(RM) $(DEPENDS)
	$(RM) $(BIN)/$(EXE)