--- tests/check_public.c.orig	Wed Jan 24 15:16:59 2007
+++ tests/check_public.c	Wed Jan 24 15:22:33 2007
@@ -70,7 +70,10 @@
 		else if(test_type == TEST_ENVIRONMENT)
 		{
 			argument = 0;
-			setenv("DISPLAY", name, 1);
+			if(name == NULL)
+				unsetenv("DISPLAY");
+			else
+				setenv("DISPLAY", name, 1);
 		}
 
 		got_host = (char *) -1;
@@ -148,7 +151,7 @@
 
 START_TEST(parse_display_negative)
 {
-	parse_display_fail(0);
+	parse_display_fail(NULL); /* modified by Ashish Shukla. 0 is not NULL in ISO C but in ISO C++ */
 	parse_display_fail("");
 	parse_display_fail(":");
 	parse_display_fail("::");
