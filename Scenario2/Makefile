PROG = excercise2
MODULES = ../modules
OBJS = ex2.o $(MODULES)/binaryTree.o  $(MODULES)/forum.o  $(MODULES)/linkedList.o

CPPFLAGS = -DUSE_BT -std=c++11

$(PROG) : clean $(OBJS)
	g++ $(OBJS) -o $(PROG) -lm 

clean :
	rm -f $(OBJS) $(PROG) 

run : $(PROG)
	./$(PROG)
