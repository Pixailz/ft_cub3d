TARGET			:= ../bin/prog_a

CC				:= gcc -Wall -Wextra -Werror -Wformat-overflow

MKDIR			= mkdir -p

SRC_C_A			:= main.c

OBJ_C_A			:= main.o

define			make_dir
	$(MKDIR) -p $1
endef

default:		$(TARGET)

$(@D):

$(TARGET):	debug $(OBJ_C_A)
	make -p $(@D)
	gcc -o $(TARGET) $(OBJ_C_A)

debug:

$(OBJ_C_A):		$(SRC_C_A)
	gcc -o $@ -c $<
