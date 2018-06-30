.PHONY : clean

VPATH = source object header
#vpath %.c ./source
#vpath %.o ./object
#vpath %.h ./header

CC = gcc
SOURCE := $(shell ls ./source/)
OBJECT := $(SOURCE:%.c=%.o)
HDR := ./header
GLIB := /usr/include/glib-2.0/
GLIB_HEADER := /usr/lib/x86_64-linux-gnu/glib-2.0/include
exe : $(OBJECT) 
	$(CC) -o $@ $^ -lglib-2.0
	mv *.o ./object/

%.o : %.c 
	$(CC) -c $^  -I $(HDR) -I $(GLIB) -I $(GLIB_HEADER)

clean : 
	rm exe ./object/*.o

