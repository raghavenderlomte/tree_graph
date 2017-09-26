CC=gcc 

FLAGS = -I include/ -g   
OBJPATH1= source/
OBJPATH2= test/

default:executable clean

executable:main.o src.o
	$(CC) -o executable main.o src.o

main.o:$(OBJPATH2)main.c
	$(CC) $(FLAGS) -c $(OBJPATH2)main.c

src.o:$(OBJPATH1)src.c
	$(CC) $(FLAGS) -c $(OBJPATH1)src.c

clean:
	rm -rf main.o src.o
