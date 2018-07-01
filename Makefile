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
GLIB_HEADER1 := /usr/include/glib-2.0/
GLIB_HEADER2 := /usr/lib/x86_64-linux-gnu/glib-2.0/include
JSON_HEADER := /usr/local/include

GLIB := -lglib-2.0 -ljson-c

cli : $(CLIENT_OBJECT) 
	$(CC) -o $@ $^ $(GLIB)
	mv *.o ./object/

ser : $(SERVER_OBJECT)
	$(CC) -o $@ $^ $(GLIB)
	mv *.o ./object/

%.o : %.c 
	$(CC) -c $^  -I $(HDR) -I $(GLIB_HEADER1) -I $(GLIB_HEADER2)

clean : 
	rm -rf cli ser ./object/*.o

