#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:09:55 by yongmkim          #+#    #+#              #
#    Updated: 2022/07/11 10:51:38 by yongmkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#░░░░░░███╗░░░███╗░█████╗░██╗░░██╗███████╗███████╗██╗██╗░░░░░███████╗░░░░░░░░░░
#░░░░░░████╗░████║██╔══██╗██║░██╔╝██╔════╝██╔════╝██║██║░░░░░██╔════╝░░░░░░░░░░
#░░░░░░██╔████╔██║███████║█████═╝░█████╗░░█████╗░░██║██║░░░░░█████╗░░░░░░░░░░░░
#░░░░░░██║╚██╔╝██║██╔══██║██╔═██╗░██╔══╝░░██╔══╝░░██║██║░░░░░██╔══╝░░░░░░░░░░░░
#░░░░░░██║░╚═╝░██║██║░░██║██║░╚██╗███████╗██║░░░░░██║███████╗███████╗░░░░░░░░░░
#░░░░░░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝╚══════╝╚══════╝░░░░░░░░░░
#==============================================================================
#	Color
#==============================================================================
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
ORANGE		=	\e[38;5;214m
BLUE_PURPLE	=	\e[38;5;057m
PURPLE		=	\e[38;5;165m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_SUCCESS_	=	[$(ORANGE)SUCCESS$(RESET)]
_INFO		=	[$(ORANGE)INFO$(RESET)]
_NAME		=	[$(GREEN)$(NAME)$(RESET)]
_CLEAN		=	[$(BLUE_PURPLE)$(NAME)$(RESET)]
_NAME_B		=	[$(GREEN)$(NAME_B)$(RESET)]
_PROG		=	$(_INFO) [$(ORANGE)$(NAME)$(RESET)] - Compile $(YELLOW)
_DONE		=	$(GREEN)✓$(RESET)
#	Loading bar
#==============================================================================
SHELL	=	/bin/bash
sp		=	/-\|/
idx		=	0
#░░░░░░░░░░░░░░░░░░░░██╗░░░██╗░█████╗░███╗░░░███╗░█████╗░░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░╚██╗░██╔╝██╔══██╗████╗░████║██╔══██╗░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░╚████╔╝░██║░░██║██╔████╔██║███████║░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░╚██╔╝░░██║░░██║██║╚██╔╝██║██╔══██║░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░░██║░░░╚█████╔╝██║░╚═╝░██║██║░░██║░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░░╚═╝░░░░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝░░░░░░░░░░░░░░░░░░░░░░
#==============================================================================
# 	Target Name
#==============================================================================
NAME		=	megaphone

#==============================================================================
#	Source
#==============================================================================
SRC			=	megaphone.cpp \

SRC_B		=

#==============================================================================
#	Directory
#==============================================================================
OBJ_DIR		=	object/
SRC_DIR		=
INC_DIR		=
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
OBJ_B		=	$(addprefix $(OBJ_DIR), $(SRC_B:.cpp=.o))
LIB_LNK		=	-I $(INC_DIR)

#OBJECT		=	$(OBJ)
ifdef WITH_BONUS
	OBJECT	+=	$(OBJ_B)
else
	OBJECT	+=	$(OBJ)
endif

#==============================================================================
#	Compile
#==============================================================================
CXX			=	C++
CC_W_FLAGS	=	all extra error
CXXFLAGS	+=	$(addprefix -W, $(CC_W_FLAGS))
RM			=	rm
RM_FLAGS	=	-f
AR			=	ar
AR_FLAGS	=	rcus
SNTZ		=	-g -fsanitize=address -fno-omit-frame-pointer
THREAD		=	-g -fsanitize=thread -fno-omit-frame-pointer
MEM			=	-g -fsanitize=memory -fsanitize-memory-track-origins \
				-fPIE -pie -fno-omit-frame-pointer
LEAK		=	-g -fsanitize=leak
DEBUG		=	-g
PTH_FLAGS	=	-pthread
#==============================================================================
#	Basic Flag
#==============================================================================
CFLAGS		=	$(CXXFLAGS)
TEMP		=
DEFINE		=	-DLEAK_CHECK=1

















#==============================================================================
#	Make Part
#==============================================================================
.PHONY		:	all
all			:
		@make $(NAME)

$(NAME)		:	$(OBJECT)
		@if [ $(idx) -gt 0 ]; then\
			printf "\b$(_DONE)\n";\
		fi
		@$(CXX) $(CFLAGS) $^ -o $@
		@printf "$(_SUCCESS) $(_NAME) - all $(_DONE)\n"

#==============================================================================
#	Object file, library Make
#==============================================================================
.PHONY		:	obj_dir
obj_dir		:
		@mkdir -p $(OBJ_DIR)

$(OBJECT)	:	obj_dir

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(INC_DIR)
		$(eval idx = $(shell expr $(idx) + 1))
		$(eval t_idx = $(shell expr $(idx) % 4 + 1))
		$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
		@if [ $(idx) = 1 ]; then\
			printf "   $(_PROG) ";\
		fi
		@printf "\b$(chr)"
		@$(CXX) $(CFLAGS) -o $@ -c $<
#@$(CXX) $(CFLAGS) $(LIB_LNK) -o $@ -c $<

#==============================================================================
#	clean fclean re
#==============================================================================
.PHONY		:	clean fclean re clear fclear c f
c			:	clean
clear		:	clean
clean		:
		@$(RM) -rf $(OBJ_DIR)
		@printf "   $(_INFO) $(_CLEAN) - clean $(_DONE)\n"
f			:	fclean
fclear		:	fclean
fclean		:
		@make clean
		@$(RM) -f $(NAME)
		@printf "   $(_INFO) $(_CLEAN) - fclean $(_DONE)\n"

re			:
		@make fclean
		@make all

b			:	bonus
bonus		:
		@make WITH_BONUS=1 all
		@printf "$(_SUCCESS_) $(_NAME) - bonus $(_DONE)\n"




#==============================================================================
#	Sanitizer Memory Leak
#==============================================================================
.PHONY		:	sntz mem leak m s thread atexit
s			:	sntz
sntz		:	CFLAGS+=$(SNTZ)
sntz		:	all
		@printf "$(_SUCCESS_) $(_NAME) - sntz $(_DONE)\n"

thread		:	CFLAGS+=$(THREAD)
thread		:	all
		@printf "$(_SUCCESS_) $(_NAME) - thread $(_DONE)\n"

m			:	mem
mem			:	CFLAGS+=$(MEM)
mem			:	all
		@printf "$(_SUCCESS_) $(_NAME) - mem $(_DONE)\n"

#atexit		:	TEMP+=$(DEFINE)
#atexit		:	all
#		@printf "$(_SUCCESS_) $(_NAME) - atexit $(_DONE)\n"

leak		:	CFLAGS+=$(LEAK)
leak		:	all
		@printf "$(_SUCCESS_) $(_NAME) - leak $(_DONE)\n"

#==============================================================================
#	Debug
#==============================================================================
.PHONY		:	debug lldb d
lldb		:	debug
d			:	debug
debug		:	CFLAGS+=$(DEBUG)
debug		:	all
		@printf "$(_SUCCESS_) $(_NAME) - debug $(_DONE)\n"

#==============================================================================
#	Show & Command List
#==============================================================================
.PHONY		:	show command com list
list		:	show
show		:	command
		@make big_flag
		@printf "NAME	: $(NAME)\n"
		@printf "CXX	: $(CC)\n"
		@printf "CXXFLAGS	: $(CC_FLAGS)\n"
		@printf "PTH_FLAGS: $(PTH_FLAGS)\n"
		@printf "SRC_DIR	: $(SRC_DIR)\n"
		@printf "OBJ_DIR	: $(OBJ_DIR)\n"
		@printf "INC_DIR	: $(INC_DIR)\n"
		@printf "SRC	: $(SRC)\n"
		@printf "COMPILE	: $(CC) $(CFLAGS) $(LIB_LNK) $(OBJECT)\n"
		@printf "\n"

com			:	command
command		:
		@make big_com
		@printf "all	: default, create target\n"
		@printf "clean	: del *.o\n"
		@printf "fclean	: [clean] + del target\n"
		@printf "re	: [fclean] + [all]\n"
		@printf "show	: print info\n"
		@printf "command	: print command list\n"
		@printf "sntz	: $(SNTZ)\n"
		@printf "mem	: $(MEM)\n"
		@printf "leak	: $(LEAK)\n"
		@printf "thread	: $(THREAD)\n"
		@printf "debug	: $(DEBUG)\n"
		@make big_alias
		@printf "clear	: [clean]\n"
		@printf "fclear	: [fclean]\n"
		@printf "list	: [show]\n"
		@printf "com	: [command]\n"
		@printf "lldb	: [debug]\n"
		@printf "s	: [sntz]\n"
		@printf "m	: [mem]\n"
		@printf "d	: [debug]\n"

#==============================================================================
#	Print Big text letter
#==============================================================================
.PHONY		:	big_com	big_alias big_flag
big_com		:
		@printf "\n$(YELLOW)"
		@printf "█▀▀ █▀█ █▀▄▀█ █▀▄▀█ ▄▀█ █▄░█ █▀▄   █░░ █ █▀ ▀█▀\n"
		@printf "█▄▄ █▄█ █░▀░█ █░▀░█ █▀█ █░▀█ █▄▀   █▄▄ █ ▄█ ░█░\n"
		@printf "$(RESET)"

big_alias	:
		@printf "\n$(ORANGE)"
		@printf "▄▀█ █░░ █ ▄▀█ █▀   █░░ █ █▀ ▀█▀\n"
		@printf "█▀█ █▄▄ █ █▀█ ▄█   █▄▄ █ ▄█ ░█░\n"
		@printf "$(RESET)"

big_flag	:
		@printf "\n$(GREEN)"
		@printf "█▀▀ █░░ ▄▀█ █▀▀   █░░ █ █▀ ▀█▀\n"
		@printf "█▀░ █▄▄ █▀█ █▄█   █▄▄ █ ▄█ ░█░\n"
		@printf "$(RESET)"
#==============================================================================
#	End of Makeflie
#==============================================================================
