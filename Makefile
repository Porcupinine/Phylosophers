#--------------------------------------------------------------------Executable
NAME	:= philo

#----------------------------------------------------------------------Compiler
CC 		=  -gcc

#-------------------------------------------------------------------------Flags
CFLAGS	+= -Wextra -Wall -Werror -o3
ASANFLAGS += -fsanitize=address -fsanitize=leak
ASANTHREAD += -fsanitize=thread

#-----------------------------------------------------------------------Headers
HEADERS	:= -I ./include

#------------------------------------------------------------------------Source
SRC	:= main.c \
	src/check/check_input.c \
	src/philos/actions.c src/philos/check_philos.c src/philos/create_philos.c \
	src/philos/free_philos.c src/philos/mutex.c src/philos/philos.c \
	src/philos/thread_philos.c \
	src/utils/errors.c src/utils/message.c src/utils/phi_atoi.c \
	src/utils/phi_calloc.c src/utils/phi_sleep.c src/utils/phi_strlen.c \
	src/utils/phi_strncmp.c src/utils/prints.c \
	src/utils/time.c

#-----------------------------------------------------------------------Objects
OBJS	:= ${SRC:.c=.o}

#---------------------------------------------------------------------Directory
OBJ_DIR := objs/
OBJECTS_PREFIXED := $(addprefix $(OBJ_DIR), $(OBJS))

#-------------------------------------------------------------------------Rules
all: $(NAME)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJECTS_PREFIXED)
	@$(CC) $(OBJECTS_PREFIXED) $(HEADERS) -o $(NAME)
	@echo "Philos are ready!"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "No more objs!"

fclean: clean
	@rm -f $(NAME)
	@echo "All clean!"

re: clean all

.PHONY: all, clean, fclean, re, libmlx lib42_build