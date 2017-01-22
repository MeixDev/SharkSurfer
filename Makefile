##
## Makefile for SharkSurfer Project
## GGJ 2017 - Theme "Waves"
##
## By MeixDev, ZLF, Sismoso, Crocofu & Lurivar
##

RM		= \rm -f

CC		= g++

NAME		= sharky

SRCS		=	main.cpp \
			class/MainGame.cpp \
			class/AScene.cpp \
			class/OptScreen.cpp \
			class/TitleScreen.cpp \
			class/GameOver.cpp \
			class/Player.cpp \
			class/Enemy.cpp \
			class/EnSprite.cpp \
			class/About.cpp \
			class/OnWaves.cpp \
			class/Dialog.cpp \
			class/Intro.cpp \
			class/OnWaves1.cpp \
			class/Shop.cpp \
			class/Anim.cpp

OBJS		= $(SRCS:.cpp=.o)

SHEETIES	= $(OBJS)

CFLAGS		= -W -Wall -Werror -Wextra -std=c++11 -Iinclude/

LIB		= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:            $(NAME)

$(NAME):       $(OBJS)
		@echo -e "\e[0m"
		@$(CC) $(OBJS) $(LIB) -o $(NAME)
		@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME) "\e[32mcreated !\e[0m"

clean:
		@echo -en "\e[0mCleaning .o && .c~ files..."
		@$(RM) $(SHEETIES)
		@echo -e "	 [\e[32mOk !\e[0m]"

fclean:         clean
		@echo -en "\e[39mCleaning executable..."
		@$(RM) $(NAME)
		@echo -e "		 [\e[32mOk !\e[0m]"

re:             fclean all

comp:           re
		@echo -en "\e[0mCleaning .o && .c~ files..."
		@$(RM) $(SHEETIES)
		@echo -e "	 [\e[32mOk !\e[0m]"

.cpp.o:           %.c
		@$(CC) -c $< -o $@ $(CFLAGS) && \
		echo -e "\e[32m[OK]" $< "\e[93m"|| \
		echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

.PHONY:         all clean fclean re comp
