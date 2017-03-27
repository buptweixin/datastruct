TARGET = app
INC = -I.
VPATH = .
SRC_PATH = $(foreach dir, $(subst :, ,$(VPATH)), $(wildcard $(dir)/, *.cpp))
OBJ_DIR = ./obj
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(subst :, ,$(VPATH)))
OBJS = $(addprefix $(OBJ_DIR)/, $(subst .cpp,.o,$(SRC_PATH)))
MAKE_OBJECT_DIR := $(shell mkdir -p $(OBJ_DIR) $(OBJ_PATH))

CXX = g++
CXXFLAG = -std=c++11

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(INC) $(CXXFLAG)

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) -o $@ -c $< $(INC) $(CXXFLAG)


.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(TARGET)


