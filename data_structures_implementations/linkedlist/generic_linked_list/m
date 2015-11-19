OBJS = singlyLinkedList.o main.o
CC  = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)


singlyLinkedList : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o singlyLinkedList

clean:
	rm -f *.o