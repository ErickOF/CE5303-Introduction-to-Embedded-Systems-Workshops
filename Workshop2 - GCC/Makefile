.PONY: build-w-slib build-w-dlib


LIB_DIR=lmath
LIB_FILE=lmath
LIB_BUILD=libmath
MAIN=calculadora

build-w-slib:
	@echo "Building static library..."
	@# Creating object code
	@gcc -c $(LIB_DIR)/$(LIB_FILE).c
	@# Creating library
	@ar rv $(LIB_BUILD).a $(LIB_FILE).o
	@rm $(LIB_FILE).o
	@ranlib $(LIB_BUILD).a
	@nm -s $(LIB_BUILD).a
	@echo "Completed"
	@gcc -o $(MAIN) $(MAIN).c $(LIB_BUILD).a -lm
	@./$(MAIN)

build-w-dlib:
	@echo "Building dynamic library"
