# DEFINITIONS
C				= c++
DEPENDENCIES	= include
RM				= rm -rf
NAME			= aoc1
FILE_NAME		= lists.txt
CFLAGS			= -W -Wall -Werror -Wextra -pedantic -g -I $(DEPENDENCIES)
VG				= valgrind --leak-check=full -s --track-origins=yes #--log-file=leaks.log

# DIRECTORIES
SRC_DIR		= src
CLASSES_DIR = classes
DIR_CLASSES	= 
DIRS		= $(addprefix $(CLASSES_DIR)/, $(DIR_CLASSES))
PATHS		= $(addprefix $(SRC_DIR)/, $(DIRS))
OBJ_DIR		= obj/
vpath %.cpp src $(PATHS)

# FILES
SRCS		= main list_parser list_get_difference list_get_similarity
OBJS		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
OBJS_FILES	= .tst

# COMPILATION
all : $(NAME)

$(NAME) : $(OBJS)
	@$(C) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o : %.cpp | $(OBJS_FILES)
	@echo "Compiling: $<"
	@$(C) $(CFLAGS) -c $< -o $@

$(OBJS_FILES) :
	@mkdir -p $(OBJ_DIR)

clean :
	@$(RM) $(OBJ_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

leaks : all
	@$(VG) ./$(NAME) $(FILE_NAME)

debug : all
	@gdb -tui $(NAME)

run : all
	@./$(NAME) ${FILE_NAME}

.SILENT:

.PHONY : all, clean, fclean, re, leaks, debug, run

