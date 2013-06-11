ROOT = ../../..

COMPILER = Lexer.java Parser.java

INITIAL_TARGETS = $(COMPILER)
OTHER_CLEAN = cleancompiler

include $(ROOT)/Makefile.include

Lexer.java: Lexer.jflex
	java JFlex.Main Lexer.jflex $<

Parser.java: Parser.cup
	java java_cup.Main -parser Parser < $<

cleancompiler:
	rm -f $(COMPILER)

