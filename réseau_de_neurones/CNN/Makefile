CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -std=c99 -O3 -g
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image -lm

all: train2

train2: ../../Tools/pixel_operations.o LeNet.o ../../Tools/matrix.o ../../pré-traitement/binarisation/binarisation.o  ../../Tools/image_operations.o train2.o

train2/.o: pixel_operations.h matrix.h binarisation.h LeNet.h image_operations.h

clean:
	${RM} *.o
	${RM} *.d
	${RM} ../../Tools/*.o
	${RM} ../../Tools/*.d
	${RM} ../../pré-traitement/binarisation/*.o
	${RM} ../../pré-traitement/binarisation/*.d
	${RM} train2
