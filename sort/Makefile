CC = gcc
CFLAGS = -fsanitize=address -fno-omit-frame-pointer -O1 -g

objects = sort.o insertionsort.o mergesort.o

sort : $(objects)
	$(CC) -o sort $(CFLAGS) $(objects)

mergesort.o : sort.h

insertionsort.o : sort.h

sort.o : sort.h

.PHONY : clean

clean:
	rm -f sort *.o *~