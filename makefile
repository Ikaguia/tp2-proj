CC=g++
RMDIR = rm -rf
RM = rm -f

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d
DIRECTIVES = -std=c++14 -Wall -Wextra -I $(HEADER_PATH) -O2
LIBS = -L$(LIB_PATH)

SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep
LIB_PATH = lib
HEADER_PATH = $(SRC_PATH)/headers

CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEP_FILES = $(wildcard $(DEP_PATH)/*.d)

EXEC = batata


all: $(EXEC)
$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)
run: clear all
	./$(EXEC)

$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp
	@mkdir -p $(DEP_PATH) $(BIN_PATH)
	$(CC) $(DEP_FLAGS) -c -o $@ $< $(DIRECTIVES)
-include $(DEP_FILES)

clean:
	$(RMDIR) $(BIN_PATH) $(DEP_PATH)
	$(RM) $(EXEC)	

clear:
	clear && clear

debug: DIRECTIVES += -ggdb -O0 -D DEBUG
debug: run

remake: clear clean all

print-% : ; @echo $* = $($*)
comp-% : ; $(CC) $* $(DIRECTIVES) $(LIBS)

.PRECIOUS: $(DEP_PATH)/%.d
.PHONY: all run clean clear debug remake
