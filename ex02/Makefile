NAME	:=	a.out
CXX		:=	c++
RM		:=	rm -f
CXXFLAGS	:=	-Wall -Wextra -Werror

DEBUG_FLAGS	:=	-g #-fsanitize=address -fsanitize=undefined
# For M1MacBook, run the command below.
# export MallocNanoZone=0
# make debug
# unset MallocNanoZone
# env | grep Malloc
NO_BUILTIN_FLAGS	:=	-fno-builtin
OBJDIR	:=	./objs
SRCS	:=	main.cpp
OBJS	:=	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# suffix rule
$(OBJDIR)/%.o:	%.cpp
	mkdir -p $(OBJDIR)
	${CXX} ${CXXFLAGS} -c $< -o $@

all		: $(NAME)

clean	:
	if [ -e $(OBJDIR) ]; then \
		rm -rf $(OBJDIR);\
	fi

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

nm		: fclean $(OBJS)
	$(CXX) $(CXXFLAGS) $(NO_BUILTIN_FLAGS) $(OBJS) -o $(NAME)
	nm -u $(NAME)

debug	: fclean $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(OBJS) -o $(NAME)

leak	:
	leaks -quiet -atExit -- ./$(NAME)

.PHONY	: all clean fclean re nm debug leak
