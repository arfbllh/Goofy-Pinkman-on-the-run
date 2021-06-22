echo "Enter your cpp file name:"
read cpp
g++ $cpp -w -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o run && ./run

