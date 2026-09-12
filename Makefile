CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes

LIBDIR = libs

LIBSTRDIR = $(LIBDIR)/libstr
LIBSTR = $(LIBSTRDIR)/libstr.h

VPATH = sources:sources/hashTable:sources/hashTableNode
SRCS =	HashTable_cpy.c HashTable_destroy.c HashTable_display.c HashTable_first.c HashTable_get.c HashTable_max.c HashTable_new.c HashTable_set.c \
		HTNode_append.c HTNode_cpy.c HTNode_destroy.c HTNode_get.c HTNode_max.c HTNode_new.c \
		hash.c

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NAME = libHashTable.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

$(OBJDIR)/%.o : %.c | $(OBJDIR) $(LIBSTR)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES) -I $(LIBSTRDIR)

$(LIBSTR) : | $(LIBSTRDIR)
	git clone https://github.com/julienPR86/libstr.git $(LIBSTRDIR)

$(OBJDIR) :
	mkdir -p $@

$(LIBSTRDIR) : | $(LIBDIR)
	mkdir -p $@

$(LIBDIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
