.PONY: build-w-slib build-w-dlib clean

LIB_DIR=lib
SRC_DIR=src
BIN_DIR=bin
LIB_BUILD=liboperaciones
MAIN=calculadora


build-w-slib:
	@cd $(LIB_DIR) && make build-slib && cd ..
	@cd $(SRC_DIR) && make build-w-slib && cd ..
	@./$(BIN_DIR)/$(MAIN)_e

build-w-dlib:
	@cd $(LIB_DIR) && make build-dlib && cd ..
	@cd $(SRC_DIR) && make build-w-dlib && cd ..
	@./$(BIN_DIR)/$(MAIN)_d

clean:
	@[ ! -d $(BIN_DIR) ] || rm -r $(BIN_DIR)
	@[ ! -f $(LIB_DIR)/$(LIB_BUILD).* ] || rm $(LIB_DIR)/$(LIB_BUILD).*
