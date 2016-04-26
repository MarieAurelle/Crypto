# project name (generate executable with this name)
TARGET = programme
TARGETPATH = ./bin

CC = gcc
# compiling flags here
CFLAGS = -Wall -lm -g

# change these to set the proper directories where each files should be
OBJ_DIR = obj
SRC_DIR = src
BIN_DIR = bin

$(TARGET) : $(OBJ_DIR)/main.o $(OBJ_DIR)/chiffrement.o $(OBJ_DIR)/affichage.o $(OBJ_DIR)/conversion.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/chiffrement.o $(OBJ_DIR)/affichage.o $(OBJ_DIR)/conversion.o -o $(BIN_DIR)/$(TARGET)
	
$(OBJ_DIR)/conversion.o : $(SRC_DIR)/conversion.c $(SRC_DIR)/conversion.h 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/conversion.c -o $(OBJ_DIR)/conversion.o

$(OBJ_DIR)/affichage.o : $(OBJ_DIR)/conversion.o $(SRC_DIR)/affichage.c $(SRC_DIR)/affichage.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/affichage.c -o $(OBJ_DIR)/affichage.o

$(OBJ_DIR)/chiffrement.o : $(OBJ_DIR)/affichage.o $(SRC_DIR)/chiffrement.c $(SRC_DIR)/chiffrement.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/chiffrement.c -o $(OBJ_DIR)/chiffrement.o
	
$(OBJ_DIR)/main.o: $(OBJ_DIR)/chiffrement.o $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*
