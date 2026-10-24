CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes



OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

LIBSDIR = libs

LIBSTRDIR = $(LIBSDIR)/libstr
LIBSTR = $(LIBSTRDIR)/libstr.h

LIBLLISTDIR = $(LIBSDIR)/libllist
LIBLLIST = $(LIBLLISTDIR)/libllist.h

NAME = libHashTable.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

$(OBJDIR)/%.o : %.c | $(OBJDIR) $(LIBSTR) $(LIBLLIST)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES) -I $(LIBSTRDIR) -I $(LIBLLISTDIR)

$(LIBSDIR) :
	mkdir -p $@

$(LIBSTRDIR) : | $(LIBSDIR)
	mkdir -p $@

$(LIBSTR) : $(LIBSTRDIR)
	git clone https://github.com/julienPR86/libstr.git $@

$(LIBLLISTDIR) : | $(LIBSDIR)
	mkdir -p $@

$(LIBLLIST) : $(LIBLLISTDIR)
	git clone https://github.com/julienPR86/libllist.git $@

$(OBJDIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

lclean :
	rm -rf $(LIBSDIR)

re : fclean all

.PHONY : all clean lclean fclean re
