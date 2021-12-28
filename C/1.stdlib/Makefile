.KEEP_STATE:

VERSION = 0.0.1

it: all
CC = cc

INC = -I. -I/home/wideshot/study/include
LIBRARY = -lpthread
CFLAGS = -g -Wall -DDEBUG -fPIC -Werror
LDFLAGS = -L. \
			${LIBRARY}
SRCS = mystdlib.c
OBJS = mystdlib.o
ALL_TARGET = libmystdlib.so.*
TARGET = libmystdlib.so.$(VERSION)

SRCS2 = main.c test/memoryTest.c test/stringTest.c
OBJS2 = main.o test/memoryTest.o test/stringTest.o
TARGET2 = main

all: $(TARGET) $(TARGET2)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

$(TARGET): $(OBJS)
	$(CC) -shared -Wl,-soname,$@ -o $@ $(OBJS) $(LDFLAGS)

$(TARGET2): $(OBJS2)
	$(CC) -o $@ $(OBJS2) $(LDFLAGS) -lmystdlib 


ori: $(TARGET2)
	

clean:
	rm -rf $(OBJS) $(OBJS2) $(TARGET) $(ALL_TARGET) $(EXECUTE) $(TARGET2)