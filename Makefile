NAME =	ft_ls

SRC =	main.c\
		add_color.c\
		aff_l.c\
		sort_file.c\
		command_list.c\
		dir_cpy.c\
		file_list.c\
		ft_ls.c\
		other_command.c\
		parsing.c\
		read_a_dir.c\
		rec_ls.c\
		help_menu.c\
		time_add.c\
		aff_l_second.c\
		check_and_sort.c\
		sort_dir.c\
		display_ls.c\
		size_and_link.c\
		path_name.c\

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) 
	make -C libft
	gcc -o $(NAME) $(OBJ) -L libft -lft

%.o: %.c libft/libft.h
	gcc -c -I libft $< -o $@

.PHONY: clean fclean re

clean:
	make -C libft fclean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all