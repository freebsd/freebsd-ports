*** lex.l.orig	Wed Mar 10 20:57:51 1993
--- lex.l	Mon Dec  5 08:06:40 1994
***************
*** 43,48 ****
--- 43,61 ----
  
  extern int ParseError;
  
+ #undef YY_INPUT
+ #define YY_INPUT(buf,result,max_size) \
+ 	{ \
+ 		int res = (*twmInputFunc)(); \
+ 		if (res == NULL) \
+ 			result = YY_NULL; \
+ 		else \
+ 		{ \
+ 			buf[0] = res; \
+ 			result = 1; \
+ 		} \
+ 	}
+ 
  %}
  
  string				\"([^"]|\\.)*\"
***************
*** 98,107 ****
  #endif
  
  #undef unput
! #undef input
  #undef output
  #undef feof
  #define unput(c)	twmUnput(c)
! #define input()		(*twmInputFunc)()
  #define output(c)	TwmOutput(c)
  #define feof()		(1)
--- 111,120 ----
  #endif
  
  #undef unput
! /*#undef input*/
  #undef output
  #undef feof
  #define unput(c)	twmUnput(c)
! /*#define input()		(*twmInputFunc)()*/
  #define output(c)	TwmOutput(c)
  #define feof()		(1)
