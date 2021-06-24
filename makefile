CC = g++
OBJ = main.cpp
OBJ_NAME = play
LINKER = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all:$(OBJ)
	$(CC) $(OBJ) -w $(LINKER) -o $(OBJ_NAME)
