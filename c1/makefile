# java
NAME = Q_1_4

# RUN: $(NAME).class
# 	java $(NAME)
# 	rm -rf *.class
# $(NAME).class:
# 	javac $(NAME).java
# clean:
# 	rm -rf *.class

# C/C++
RUN: $(NAME)
	./$(NAME)
	rm -rf $(NAME) *.o
$(NAME): $(NAME).o
	g++ -o $@ $^
.c.o:
	g++ -c $<
clean:
	rm -rf $(NAME) *.o