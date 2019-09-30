CC = gcc
CPPFLAGS = -ansi -pedantic -Wall -Wextra -I./include

.PHONY: all clean archive git

all: bin  ./bin/iplot

bin :
	mkdir ./bin/

./bin/iplot: src/iplot.cpp include/iplot.h
	$(CXX) $^ -o $@ $(CPPFLAGS)

clean:
	find . -type f -name '*.o' -exec rm {} +
	find . -type f -name '*\~' -exec rm {} +
	rm ./bin/*
	rmdir ./bin/

archive:
	make -i clean
	tar -czvf HUBERT_TP1_OS.tar ./*

git:
	make -i clean
	git add .
	git commit
	git push
