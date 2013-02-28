package pubsub.edl2.frontendComposite;

import java_cup.runtime.*;
%%
%cup
%class Lexer
%unicode
%line
%column
%{
	private Symbol symbol(int type) {
		return new Symbol(type, yyline, yycolumn);
	}
	private Symbol symbol(int type, Object value) {
		return new Symbol(type, yyline, yycolumn, value);
	}
	public void errorMsg(String message, Symbol info) {
	}
%}
%eofval{
    return symbol(sym.EOF);
%eofval}

LineTerminator			=	\r|\n|\r\n
InputCharacter			=	[^\r\n]
WhiteSpace			=	{LineTerminator} | [ \t\f]

/* comments */
Comment				=	{TraditionalComment} | {EndOfLineComment} | {DocumentationComment}

TraditionalComment		= "/*" [^*] ~"*/" | "/*" "*"+ "/"
EndOfLineComment		= "//" {InputCharacter}* {LineTerminator}
DocumentationComment		= "/**" {CommentContent} "*"+ "/"
CommentContent			= ( [^*] | \*+ [^/*] )*

Identifier			=	[:jletter:] [:jletterdigit:]*

/* literals */
DecIntegerLiteral		= 0 | [1-9][0-9]*
OctIntegerLiteral		=	0[0-9]+
HexIntegerLiteral		=	0x[0-9]+
BoolLiteral			= (true)|(false)

%%
/* keywords */
<YYINITIAL>	"boolean"	{ return symbol(sym.BOOLEAN); }
<YYINITIAL>	"on"		{ return symbol(sym.ON); }
<YYINITIAL>	"where"		{ return symbol(sym.WHERE); }
<YYINITIAL>	"area"		{ return symbol(sym.AREA); }
<YYINITIAL>	"event"		{ return symbol(sym.EVENT); }
<YYINITIAL>	"and"		{ return symbol(sym.AND); }
<YYINITIAL>	"or"		{ return symbol(sym.OR); }
<YYINITIAL>	"subscribe"	{ return symbol(sym.SUBSCRIBE); }
<YYINITIAL>	"int"		{ return symbol(sym.INT); }
<YYINITIAL>	"long"		{ return symbol(sym.LONG); }
<YYINITIAL>	"float"		{ return symbol(sym.error); }
<YYINITIAL>	"double"	{ return symbol(sym.error); }

<YYINITIAL> {
	/* literals */
	{DecIntegerLiteral}	{ return symbol(sym.INTEGER_LITERAL, yytext()); }
	{BoolLiteral}		{ return symbol(sym.BOOLEAN_LITERAL, yytext()); }
	\"			{ return symbol(sym.error); } // String not supported yet

	/* identifiers */ 
	{Identifier}		{ return symbol(sym.IDENTIFIER, yytext()); }

	";"			{ return symbol(sym.SEMICOLON); }
	/* operators */
	","			{ return symbol(sym.COMMA); }
	"{"			{ return symbol(sym.LBRACE); }
	"}"			{ return symbol(sym.RBRACE); }
	"("			{ return symbol(sym.LPAREN); }
	")"			{ return symbol(sym.RPAREN); }

	/* Array (not supported yet) */
	"["			{ return symbol(sym.error); }
	"]"			{ return symbol(sym.error); }

	"."			{ return symbol(sym.DOT); }

	/* Arithmetic */
	"++"			{ return symbol(sym.PLUSPLUS); }
	"--"			{ return symbol(sym.MINUSMINUS); }

	"*"			{ return symbol(sym.MULT); }
	"%"			{ return symbol(sym.MOD); }
	"/"			{ return symbol(sym.DIV); }

	"+"			{ return symbol(sym.PLUS); }
	"-"			{ return symbol(sym.MINUS); }

	/* Bitwise */
	">>"			{ return symbol(sym.RSHIFT); }
	"<<"			{ return symbol(sym.LSHIFT); }
	"&"			{ return symbol(sym.AND); }
	"|"			{ return symbol(sym.OR); }
	"^"			{ return symbol(sym.XOR); }

	/* Logic */
	">="			{ return symbol(sym.GTEQ); }
	">"			{ return symbol(sym.GT); }
	"<="			{ return symbol(sym.LTEQ); }
	"<"			{ return symbol(sym.LT); }
	"=="			{ return symbol(sym.EQEQ); }
	"!="			{ return symbol(sym.NOTEQ); }
	"&&"			{ return symbol(sym.ANDAND); }
	"||"			{ return symbol(sym.OROR); }

	/* Assignment */
	"="			{ return symbol(sym.EQ); }
	"*="			{ return symbol(sym.MULTEQ); }
	"/="			{ return symbol(sym.DIVEQ); }
	"%="			{ return symbol(sym.MODEQ); }
	"+="			{ return symbol(sym.PLUSEQ); }
	"-="			{ return symbol(sym.MINUSEQ); }
	"<<="			{ return symbol(sym.LSHIFTEQ); }
	">>="			{ return symbol(sym.RSHIFTEQ); }
	"&="			{ return symbol(sym.ANDEQ); }
	"^="			{ return symbol(sym.XOREQ); }
	"|="			{ return symbol(sym.OREQ); }

	/* comments */
 	{Comment}		{ /* ignore */ }
 
	/* whitespace */
 	{WhiteSpace}		{ /* ignore */ }
}

/* error fallback */
.|\n                             { return symbol(sym.error); }
