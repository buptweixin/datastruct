TARGET = app
INC = -I. -I../list
VPATH = .:../list
SRC_PARH = $(foreach dir, $(subst :, ,$(VPATH)), $(wildcard $(dir)/, *.cpp))
OBJ_DIR = ./obj
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(subst :, ,$(VPATH)))
OBJS = $(addprefix $(OBJ_DIR)/, $(subst .cpp,.o,$(SRC_PARH)))
MAKE_OBJECT_DIR := $(shell mkdir -p $(OBJ_DIR) $(OBJ_PATH))

CXX = g++
CXXFLAGS=-std=c++11

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(INC) $(CXXFLAGS)

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) -o $@ -c $< $(INC) $(CXXFLAGS)

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(TARGET)
