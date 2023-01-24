TARGET		:= test

PRINTF		:= @printf

SRC_DIR		:= mandatory

SRC_C		:= main.c				\
			   rendering/utils.1.c	\

OBJ_C		:= $(addprefix $(SRC_DIR)/,$(SRC_C))

all:		debug

debug:
	$(PRINTF) "OBJ_C {%s}\n" $(OBJ_C)
	$(PRINTF) "$(@D)%s\n" $(@D)
