CC = gcc
CPPFLAGS = -ansi -pedantic -Wall -Wextra -I./include

.PHONY: all clean archive git

all: bin ./bin/iplot

bin :
	mkdir ./bin/

./bin/iplot: src/iplot.c include/iplot.h src/main.c
	$(CC) $^ -o $@ $(CPPFLAGS)

clean:
	find . -type f -name '*.o' -exec rm {} +
	find . -type f -name '*\~' -exec rm {} +
	rm ./bin/*
	rmdir ./bin/

archive:
	make -i clean
	zip -r HUBERT_TP1_OS.zip ./*

git:
	make -i clean
	git add .
	git commit
	git push
