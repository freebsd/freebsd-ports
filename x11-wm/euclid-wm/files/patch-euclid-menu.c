--- euclid-menu.c.orig	2016-12-17 00:40:07 UTC
+++ euclid-menu.c
@@ -211,7 +211,7 @@ void load_handlers() {
 	chdir(getenv("HOME")); //so when we run a program it isn't in a config dir. 
 }
 
-inline char* find_handler() {
+static inline char* find_handler() {
 	//read buf use an aray to pick the appropriate file handler and return the command
 //what is here now is a bit simple, we need to also check the end of the line to see whether the returned command is prompting for another handler (e.g., if the command takes a filename or a URL as an argument
 	if (buf[0] == ':') {
