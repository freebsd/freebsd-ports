--- lex.l.orig	1993-03-10 20:57:51 UTC
+++ lex.l
@@ -43,6 +43,19 @@ extern char *ProgramName;
 
 extern int ParseError;
 
+#undef YY_INPUT
+#define YY_INPUT(buf,result,max_size) \
+	{ \
+		int res = (*twmInputFunc)(); \
+		if (res == NULL) \
+			result = YY_NULL; \
+		else \
+		{ \
+			buf[0] = res; \
+			result = 1; \
+		} \
+	}
+
 %}
 
 string				\"([^"]|\\.)*\"
@@ -98,10 +111,10 @@ yywrap() { return(1);}
 #endif
 
 #undef unput
-#undef input
+/*#undef input*/
 #undef output
 #undef feof
 #define unput(c)	twmUnput(c)
-#define input()		(*twmInputFunc)()
+/*#define input()		(*twmInputFunc)()*/
 #define output(c)	TwmOutput(c)
 #define feof()		(1)
