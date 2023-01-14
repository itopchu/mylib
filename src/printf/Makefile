NAME	= printf.a
HEADER	= ../header/
ARCHIVE_NAME = $(NAME)
####################################
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -I$(HEADER)
RM		= rm -rf
####################################
AR		= ar
ARFLAGS	= -rcs
ARCHIVE	= $(AR) $(ARFLAGS)
####################################
DIR_OBJ	= ../obj/printf/
DIR_ARCH= ../archives/
####################################
SRC 	=	ft_printf.c \
			write.c \
			hex.c \
			based_int.c \
			base_conv.c
####################################
OBJ		= $(SRC:%.c=$(DIR_OBJ)%.o)
####################################
$(DIR_OBJ)%.o: %.c $(HEADER)
	@mkdir -p $(DIR_OBJ)
	@$(COMPILE) -c $< -o $@
	@echo "Objects created and put in $(DIR_OBJ)."

$(DIR_ARCH)$(ARCHIVE_NAME): $(OBJ)
	@mkdir -p $(DIR_ARCH)
	@$(ARCHIVE) $(DIR_ARCH)$(ARCHIVE_NAME) $(OBJ)
	@echo "Archived and put in $(DIR_ARCH)$(ARCHIVE_NAME)."
####################################
all:  $(DIR_ARCH)$(ARCHIVE_NAME)

clean:
	@$(RM) $(DIR_OBJ)
	@echo "$(DIR_OBJ) is removed with it's components."

fclean: clean
	@$(RM) $(DIR_ARCH)$(ARCHIVE_NAME)
	@echo "$(ARCHIVE_NAME) is removed in $(DIR_ARCH)"

re: fclean all

.PHONY: clean all fclean re