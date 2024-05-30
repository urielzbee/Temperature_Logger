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
CPPFLAGS += -I ./src

LDLIBS = -L$(CPPUTEST_HOME)/cpputest_build/lib -lCppUTest -lCppUTestExt

# dependency-generation flags
#DEPFLAGS = -MMD -MP

# Build
BIN = bin
OBJ = obj
SRC = ../TL_MAIN_MCU/App
TST = ./


SOURCES := \
		$(wildcard $(SRC)/*.c $(SRC)/*.cpp) \
		$(wildcard $(TST)/*.c $(TST)/*.cpp) 

OBJECTS := \
	$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c)) \
	$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(wildcard $(SRC)/*.cpp)) \
	$(patsubst $(TST)/%.cpp, $(OBJ)/%.o, $(wildcard $(TST)/*.cpp)) 


# include compiler-generated dependency rules
DEPENDS := $(OBJECTS:.o=.d)

# compile C source
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) -c -o $@

# compile C++ source
COMPILE.cxx = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@

# link objects
LINK.o = $(LD) $(LDFLAGS) $(LDLIBS) $(OBJECTS) -o $@

.DEFAULT_GOAL = all

.PHONY: all
all: $(BIN)/$(EXE)
	./$(BIN)/$(EXE)

$(BIN)/$(EXE): $(SRC) $(OBJ) $(BIN) $(OBJECTS)
	$(LINK.o)

$(SRC):
	mkdir -p $(SRC)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

$(OBJ)/%.o:	$(SRC)/%.c
	$(COMPILE.c) $<

$(OBJ)/%.o:	$(SRC)/%.cpp
	$(COMPILE.cxx) $<

$(OBJ)/%.o:	$(TST)/%.cpp
	$(COMPILE.cxx) $<

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
	$(RM) $(OBJECTS)
	$(RM) $(DEPENDS)
	$(RM) $(BIN)/$(EXE)