CC = gcc
CPPFLAGS = -ansi -pedantic -Wall -Wextra -I./include

.PHONY: all clean distclean archive git

all: bin ./bin/iplot

bin :
	mkdir ./bin/

./bin/iplot: src/iplot.c include/iplot.h src/main.c
	$(CC) $^ -o $@ $(CPPFLAGS)

distclean:
	clean
	find . -type f -name '*\~' -exec rm {} +
	rm -f ./bin/*

clean:
	find . -type f -name '*.o' -exec rm {} +

archive:
	make -i distclean
	zip -r HUBERT_TP1_OS.zip ./*

git:
	make -i distclean
	git add .
	git commit
	git push
