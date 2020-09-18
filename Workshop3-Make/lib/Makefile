.PONY: build-slib build-dlib


LIB_DIR=../include
LIB_FILE=operaciones
LIB_BUILD=liboperaciones
MAIN=calculadora


build-slib:
	@echo "Building static library..."

	@# Creating object code
	@gcc -c $(LIB_FILE).c

	@# Creating library
	@ar rv $(LIB_BUILD).a $(LIB_FILE).o
	@rm $(LIB_FILE).o

	@ranlib $(LIB_BUILD).a

	@nm -s $(LIB_BUILD).a

	@echo "Completed"

build-dlib:
	@echo "Building dynamic library..."

	@# Creating object code
	@gcc -c $(LIB_FILE).c

	@# Creating library
	@ld -o $(LIB_BUILD).so $(LIB_FILE).o -shared -lm
	@rm $(LIB_FILE).o

	@echo "Completed"
