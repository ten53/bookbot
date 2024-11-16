build:
	gcc -Wall -std=c99 src/*.c -o program

run:
	./program

clean:
	rm program
