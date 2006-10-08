--- tests/check_public.c.orig	Wed Aug 23 02:49:33 2006
+++ tests/check_public.c	Wed Aug 23 02:49:33 2006
@@ -97,7 +97,7 @@
 
 START_TEST(parse_display_negative)
 {
-	parse_display_fail(0);
+	parse_display_fail(NULL); /* modified by Ashish Shukla. 0 is not NULL in ISO C but in ISO C++ */
 	parse_display_fail("");
 	parse_display_fail(":");
 	parse_display_fail("::");
