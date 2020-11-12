PROG = excercise1
MODULES = ../modules
OBJS = ex1.o $(MODULES)/forum.o  

CPPFLAGS = -std=c++11


$(PROG) : clean $(OBJS)
	g++ $(OBJS) -o $(PROG) -lm 

clean :
	rm -f $(OBJS) $(PROG)

run : $(PROG)
	./$(PROG)
