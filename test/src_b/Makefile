TARGET			:= ../bin/prog_b

SRC_C_B			:= main.c

OBJ_C_B			:= main.o

default:	$(TARGET)

$(TARGET):	$(OBJ_C_B)
	gcc -o $(TARGET) $(OBJ_C_B)

$(OBJ_C_B):		$(SRC_C_B)
	gcc -o $@ -c $<
