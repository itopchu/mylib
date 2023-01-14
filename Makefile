NAME	= my_lib.a

RM		= rm -rf

NO_DIR	= --no-print-directory

all:
	@$(MAKE) --no-print-directory -C src/libft/
	@$(MAKE) --no-print-directory -C src/printf/
	@$(MAKE) --no-print-directory -C src/get_next_line/
	@ar -rcs $(NAME) src/obj/libft/*.o src/obj/printf/*.o src/obj/get_next_line/*.o
	@echo "$(NAME) is archived in my_lib/"

clean:
	@$(MAKE) --no-print-directory -C src/libft/ clean
	@$(MAKE) --no-print-directory -C src/printf/ clean
	@$(MAKE) --no-print-directory -C src/get_next_line/ clean
	@$(RM) src/archives/
	@$(RM) src/obj/
	@echo "directory archives removed."

fclean: clean
	@$(MAKE) --no-print-directory -C src/libft fclean
	@$(MAKE) --no-print-directory -C src/printf fclean
	@$(MAKE) --no-print-directory -C src/get_next_line fclean
	@$(RM) $(NAME)
	@echo "$(NAME) is removed in my_lib/"

re: clean all

.PHONY: all clean fclean re