NAME = Test


RUN: $(NAME).class
	java $(NAME)
	rm -rf *.class
$(NAME).class:
	javac $(NAME).java