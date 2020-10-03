.PONY: build-slib build-dlib


CC=gcc
LIB_DIR=../include
LIB_FILE=operaciones
CFILE=$(LIB_FILE).c
OUTPUT_FILE=$(LIB_FILE).o
LIB_BUILD=liboperaciones
DLIB=$(LIB_BUILD).so
SLIB=$(LIB_BUILD).a
MAIN=calculadora


build-slib:
	@$(CC) -c $(CFILE)

	@ar rv $(SLIB) $(OUTPUT_FILE)
	@rm $(OUTPUT_FILE)

	@ranlib $(SLIB)
	@nm -s $(SLIB)

build-dlib:
	@$(CC) -c $(CFILE)

	@ld -o $(DLIB) $(OUTPUT_FILE) -shared -lm
	@rm $(OUTPUT_FILE)
