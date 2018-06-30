.PHONY : clean

VPATH = client object header server
#vpath %.c ./source
#vpath %.o ./object
#vpath %.h ./header

CC = gcc
CLIENT := $(shell ls ./client)
SERVER := $(shell ls ./server)

all : cli ser 

CLIENT_OBJECT := $(CLIENT:%.c=%.o)
SERVER_OBJECT := $(SERVER:%.c=%.o)

HDR := ./header
GLIB := /usr/include/glib-2.0/
GLIB_HEADER := /usr/lib/x86_64-linux-gnu/glib-2.0/include


cli : $(CLIENT_OBJECT) 
	$(CC) -o $@ $^ -lglib-2.0
	mv *.o ./object/

ser : $(SERVER_OBJECT)
	$(CC) -o $@ $^ -lglib-2.0
	mv *.o ./object/

%.o : %.c 
	$(CC) -c $^  -I $(HDR) -I $(GLIB) -I $(GLIB_HEADER)

clean : 
	rm -rf cli ser ./object/*.o

