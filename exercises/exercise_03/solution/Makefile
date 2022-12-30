# Assign program name to variable
PROG = temp-conv
UTIL = util

temp-conv: main.o $(UTIL).o
	$(CC) $(CFLAGS) -o $(PROG) main.o $(UTIL).o

main.o: main.c $(UTIL).h
	$(CC) $(CFLAGS) -c main.c

$(UTIL).o: $(UTIL).c $(UTIL).h
	$(CC) $(CFLAGS) -c $(UTIL).c

.PHONY: clean
clean:
	rm -f *.o