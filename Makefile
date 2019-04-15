all: test

test: dirtest.c
	gcc -o $@ $< -g

clean:
	rm -rf test
