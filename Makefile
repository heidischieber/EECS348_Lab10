CC := g++
CFLAGS := -Wall

OBJS := calculator.o

matrix.exe: $(OBJS)
	$(CC) $(OBJS) -o calculator.exe

clean:
	rm -f $(OBJS) calculator.exe