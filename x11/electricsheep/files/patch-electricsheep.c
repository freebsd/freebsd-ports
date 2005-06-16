--- electricsheep.c.orig	Thu Jun 16 00:19:15 2005
+++ electricsheep.c	Thu Jun 16 00:19:59 2005
@@ -1201,6 +1201,7 @@
 time_t server_anims_timestamp = -1;
 
 void update_server_anims() {
+    XML_Parser parser; 
     char pbuf[MAXBUF];
     FILE *lf;
     int done;
@@ -1216,7 +1217,7 @@
       server_anims_timestamp = now;
     }
 	
-    XML_Parser parser = XML_ParserCreate(NULL);
+    parser = XML_ParserCreate(NULL);
     XML_SetElementHandler(parser, list_start_element, get_end_element);
     XML_SetCharacterDataHandler(parser, character_handler);
     in_message = 0;
