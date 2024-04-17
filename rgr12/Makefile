APP_NAME = myprogram
LIB_NAME = Dlist

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = prog

BIN = $(shell mkdir -p $(BIN_DIR))

CFLAGS = -Wall -mconsole -I $(SRC_DIR)/lib
DEPSFLAGS = -MMD
CC = g++

APP_PATH = $(BIN_DIR)/$(APP_NAME)

# Добавляем Dlist.cpp и array.cpp в список исходных файлов
APP_SOURCES := $(wildcard $(SRC_DIR)/myprog/*.cpp) $(SRC_DIR)/lib/Dlist.cpp $(SRC_DIR)/lib/array.cpp
APP_OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/$(SRC_DIR)/%.o, $(APP_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all clean
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

run: all
	$(APP_PATH) rgr12/bin/main.txt

clean:
	$(RM) $(APP_PATH) $(OBJ_DIR)/*/*.o $(OBJ_DIR)/*/*.d
