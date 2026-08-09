# Builds the writer application.
#
# Native build:          make
# Cross compiled build:  make CROSS_COMPILE=aarch64-none-linux-gnu-
#
# Author: Sarkar22

CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
CFLAGS ?= -Wall -Werror -g
LDFLAGS ?=

TARGET = writer
OBJS = writer.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.o
