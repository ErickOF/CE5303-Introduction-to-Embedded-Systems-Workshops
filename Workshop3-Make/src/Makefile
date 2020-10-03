.PONY: build-slib build-dlib


CC=gcc
LIB_DIR=../lib
BIN_DIR=../bin
HEADER_DIR=-I../include
LDIR=-L$(LIB_DIR)
LIB_BUILD=liboperaciones
DBUILD=$(CURDIR)/$(LIB_DIR)/$(LIB_BUILD).so
SLIB=$(LIB_DIR)/$(LIB_BUILD).a
MAIN=calculadora
MAINC=calculadora.c
MAIND=$(BIN_DIR)/calculadora_d
MAINE=$(BIN_DIR)/calculadora_e
FLAGS=-lm
BFLAGS=-Bdynamic


build-slib:
	@[ -d $(BIN_DIR) ] || mkdir $(BIN_DIR)
	@$(CC) -o $(MAINE) $(MAINC) $(SLIB) $(FLAGS)

build-dlib:
	@[ -d $(BIN_DIR) ] || mkdir $(BIN_DIR)
	@$(CC) -o $(MAIND) $(MAINC) $(HEADER_DIR) $(LDIR) $(BFLAGS) $(DBUILD) $(FLAGS)
