.PONY: build-w-slib build-w-dlib clean


LIB_DIR=lib
SRC_DIR=src
BIN_DIR=bin
DLIB=build-dlib
SLIB=build-slib
LIB_BUILD=liboperaciones


build-w-slib:
	@cd $(LIB_DIR) && make $(SLIB)
	@cd $(SRC_DIR) && make $(SLIB)

build-w-dlib:
	@cd $(LIB_DIR) && make $(DLIB)
	@cd $(SRC_DIR) && make $(DLIB)

clean:
	@[ ! -d $(BIN_DIR) ] || rm -r $(BIN_DIR)
	@[ ! -f $(LIB_DIR)/$(LIB_BUILD).* ] || rm $(LIB_DIR)/$(LIB_BUILD).*
