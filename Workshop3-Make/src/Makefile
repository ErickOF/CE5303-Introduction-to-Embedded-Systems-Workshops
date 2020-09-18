.PONY: build-w-slib build-w-dlib

LIB_DIR=../include
BUILD_DIR=../lib
BIN_DIR=../bin
LIB_BUILD=liboperaciones
MAIN=calculadora


build-w-slib:
	@echo "Building app with static library..."
	@[ -d $(BIN_DIR) ] || mkdir $(BIN_DIR)
	@gcc -o $(BIN_DIR)/$(MAIN)_e $(MAIN).c $(BUILD_DIR)/$(LIB_BUILD).a -lm
	@echo "Completed"

build-w-dlib:
	@echo "Building app with dynamic library..."
	@[ -d $(BIN_DIR) ] || mkdir $(BIN_DIR)
	@gcc -o $(BIN_DIR)/$(MAIN)_d $(MAIN).c -I$(LIB_DIR) -L$(BUILD_DIR) -Bdynamic $(CURDIR)/$(BUILD_DIR)/$(LIB_BUILD).so -lm
	@echo "Completed"
