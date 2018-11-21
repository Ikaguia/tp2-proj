CC=g++
RMDIR = rm -rf
RM = rm -f

DIRECTIVES = -std=c++14 -Wall -Wextra -I $(HEADER_PATH1) -I $(HEADER_PATH2) -O2
LIBS = -L$(LIB_PATH)

SRC_PATH1 = src
SRC_PATH2 = TP2-1/src
BIN_PATH1 = bin/1
BIN_PATH2 = bin/2
LIB_PATH = lib
HEADER_PATH1 = $(SRC_PATH1)/headers
HEADER_PATH2 = $(SRC_PATH2)/../include

CPP_FILES1 = $(wildcard $(SRC_PATH1)/*.cpp)
CPP_FILES2 = $(wildcard $(SRC_PATH2)/*.cpp)
OBJ_FILES1 = $(addprefix $(BIN_PATH1)/,$(notdir $(CPP_FILES1:.cpp=.o)))
OBJ_FILES2 = $(addprefix $(BIN_PATH2)/,$(notdir $(CPP_FILES2:.cpp=.o)))

EXEC = batata

all: $(EXEC)
$(EXEC): $(OBJ_FILES1) $(OBJ_FILES2); $(CC) -o $@ $^ $(LIBS)
run: clear all; ./$(EXEC)

$(BIN_PATH1)/%.o: $(SRC_PATH1)/%.cpp; $(CC) -c -o $@ $< $(DIRECTIVES)

$(BIN_PATH2)/%.o: $(SRC_PATH2)/%.cpp; $(CC) -c -o $@ $< $(DIRECTIVES)


#clean:
#  $(RMDIR) $(BIN_PATH)
#  $(RM) $(EXEC)  

clear:; clear && clear

debug: DIRECTIVES += -ggdb -O0 -D DEBUG
debug: run

remake: clear clean all

print-% : ; @echo $* = $($*)
comp-% : ; $(CC) $* $(DIRECTIVES) $(LIBS)

.PHONY: all run clean clear debug remake
