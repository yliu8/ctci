# java
NAME = Q_1_2

# RUN: $(NAME).class
# 	java $(NAME)
# 	rm -rf *.class
# $(NAME).class:
# 	javac $(NAME).java

# C/C++
RUN: $(NAME)
	./$(NAME)
$(NAME): $(NAME).o
	g++ -o $@ $^
.c.o:
	g++ -c $<
clean:
	rm -rf $(NAME) *.o