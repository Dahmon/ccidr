SRC_DIR     = src
BUILD_DIR   = bin
TEST_DIR    = test
INCLUDE_DIR = includes

TARGET      = $(BUILD_DIR)/ccidr
LIB_TARGET  = $(BUILD_DIR)/libccidr.a
TEST_TARGET = $(BUILD_DIR)/test

CLI_SRCS    := $(SRC_DIR)/ccidr.c
LIB_SRCS    := $(filter-out $(CLI_SRCS), $(wildcard $(SRC_DIR)/*.c))
TEST_SRCS   := $(wildcard $(TEST_DIR)/*.c)

CLI_OBJS    := $(CLI_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
LIB_OBJS    := $(LIB_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TEST_OBJS   := $(TEST_SRCS:$(TEST_DIR)/%.c=$(BUILD_DIR)/%.o)

CLI_DEBUG_OBJS := $(CLI_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_debug.o)
LIB_DEBUG_OBJS := $(LIB_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_debug.o)

CFLAGS      = -I$(INCLUDE_DIR)
DEBUG_FLAGS = -gdwarf-4 -g
TEST_FLAGS = -lcunit

.PHONY: all lib debug clean test

all: $(TARGET)

debug: $(TARGET)_debug

lib: $(LIB_TARGET)

$(TARGET): $(CLI_OBJS) $(LIB_TARGET)
	gcc -o $@ $(CLI_OBJS) $(LIB_TARGET)

$(LIB_TARGET): $(LIB_OBJS)
	ar rcs $@ $(LIB_OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) -c $< -o $@

$(TARGET)_debug: $(CLI_DEBUG_OBJS) $(LIB_TARGET)_debug
	gcc $(DEBUG_FLAGS) -o $@ $(CLI_DEBUG_OBJS) $(LIB_TARGET)_debug

$(LIB_TARGET)_debug: $(LIB_DEBUG_OBJS)
	ar rcs $@ $(LIB_DEBUG_OBJS)

$(BUILD_DIR)/%_debug.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

test: $(TEST_TARGET)
	@$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) $(LIB_TARGET)
	gcc -o $@ $(TEST_FLAGS) $(TEST_OBJS) $(LIB_TARGET)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
