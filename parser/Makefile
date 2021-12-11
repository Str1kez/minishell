all:
	gcc -Wall -Wextra -Werror *.c -L../libft -lft -I.. && ./a.out

libft:
	make -sC ../libft && make -sC ../libft clean

debug:
		gcc -Wall -Wextra -Werror -g *.c -L../libft -lft -I.. -o parser
