ifdef debug
		CFLAGS += -g -pedantic -Wall -Wextra
else
		CFLAGS += -O3
endif

program: drzewo.o main.o gruszka.o swierk.o wierzba.o
		g++ drzewo.o main.o gruszka.o swierk.o wierzba.o -o program

drzewo.o: drzewo.cpp drzewo.h
		g++ ${CFLAGS} -c drzewo.cpp -o drzewo.o

gruszka.o: gruszka.cpp gruszka.h
		g++ ${CFLAGS} -c gruszka.cpp -o gruszka.o

swierk.o: swierk.cpp swierk.h
		g++ ${CFLAGS} -c swierk.cpp -o swierk.o

wierzba.o: wierzba.cpp wierzba.h
		g++ ${CFLAGS} -c wierzba.cpp -o wierzba.o

clean:
		rm -f *.o
