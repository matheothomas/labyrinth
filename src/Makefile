CC=gcc
OPT=-Wall -Wextra -I /usr/include/SDL2
OPTSDL=-lSDL2_image -lSDL2_ttf -lSDL2

main: main.o laby.o graphics.o
	${CC} ${OPT} main.o laby.o graphics.o -o main ${OPTSDL}
main.o: main.c
	${CC} ${OPT} main.c -c
laby.o: laby.c
	${CC} ${OPT} laby.c -c
graphics.o: graphics.c
	${CC} ${OPT} graphics.c -c

clean:
	rm -f *.o *.gch

