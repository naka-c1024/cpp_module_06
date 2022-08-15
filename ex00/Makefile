NAME	:=	convert
CXX		:=	c++
RM		:=	rm -rf
CXXFLAGS	:=	-Wall -Wextra -Werror
CXXFLAGS	+=	-std=c++98 -pedantic -MMD -MP

DEBUG_FLAGS	:=	-g #-fsanitize=address -fsanitize=undefined
# For M1MacBook, run the command below.
# export MallocNanoZone=0
# make debug
# unset MallocNanoZone
# env | grep Malloc
NO_BUILTIN_FLAGS	:=	-fno-builtin
OBJDIR	:=	./objs
SRCS	:=	main.cpp Convert.cpp
OBJS	:=	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

DEPS	:=	${OBJS:%.o=%.d}
-include ${DEPS}

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# suffix rule
$(OBJDIR)/%.o:	%.cpp
	mkdir -p $(OBJDIR)
	${CXX} ${CXXFLAGS} -c $< -o $@

clean	:
	$(RM) $(OBJDIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

nm		: fclean $(OBJS)
	$(CXX) $(CXXFLAGS) $(NO_BUILTIN_FLAGS) $(OBJS) -o $(NAME)
	nm -u --demangle $(NAME)

debug	: fclean $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(OBJS) -o $(NAME)

leak	:
	leaks -quiet -atExit -- ./$(NAME)

.PHONY	: all clean fclean re nm debug leak
