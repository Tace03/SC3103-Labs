CC=gcc
PROG=helloworld
OBJS= hello-main.o hello_funct1.o hello-funct2.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

hello-main.o :
	$(CC) -c hello-main.c

hello-funct1.o : hello.h
	$(CC) -c hello-funct1.c

hello-funct2.o : hello.h
	$(CC) -c hello-funct2.c

clean:
	rm -f $(PROG) $(OBJS)