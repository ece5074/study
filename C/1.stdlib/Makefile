.KEEP_STATE:

it: all
CC = cc

LIBRARY = -lpthread
CFLAGS = -g -Wall -DDEBUG -fPIC
LDFLAGS = ${LIBRARY}
SRCS = main.c
OBJS = main.o
TARGET = libmystdlib.so.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -shared -Wl,-soname,$@ -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(TARGET)