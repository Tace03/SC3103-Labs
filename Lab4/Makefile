CC=gcc
PROG=main
CFLAGS= -lpthread
OBJS= pthread1.o

$(PROG):
	$(CC) -o $(PROG) $(OBJS) $(CFLAGS)

pthread2:
	gcc -o pthread1 pthread2.o -lpthread

mutex1:
	gcc -o mutex1 mutex1.o -lpthread

server:
	gcc -o server server.o -lpthread

client:
	gcc -o client client.o -lpthread

pthread1.o:
	$(CC) -c pthread1.c

pthread2.o:
	$(CC) -c pthread2.c

mutex1.o:
	$(CC) -c mutex1.c

server.o:
	gcc -c server.c

client.o:
	gcc -c client.c

	