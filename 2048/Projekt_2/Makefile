CC =gcc
CFLAGS= -fsanitize=address -lSDL2 -lSDL2_image -lSDL2_ttf
OBJFILE = 2048_3.o pohyb.o stvorec.o operacie.o
NAME = 2048

$(NAME): $(OBJFILE)
	$(CC) $(CFLAGS) $(OBJFILE) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean_bin:
	rm -f $(NAME)
	
clean_obj:
	rm -f *.o

clean: clean_bin clean_obj

all: celan $(NAME)
