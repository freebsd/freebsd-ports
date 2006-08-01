$FreeBSD$

--- libAfterStep/parser.c.orig	Thu Jun 22 21:33:08 2006
+++ libAfterStep/parser.c	Thu Jun 22 21:33:46 2006
@@ -771,8 +771,8 @@
 	{
 		while (GetNextStatement (config, ignore_foreign))
 		{									   /* untill not end of text */
-			flags = 0x00;
 			TermDef *pterm = NULL ; 
+			flags = 0x00;
 
 #ifdef DEBUG_PARSER
 			fprintf (stderr, "\nSentence Found:[%.50s ...]\n,\tData=\t[%s]", config->tline, config->current_data);
