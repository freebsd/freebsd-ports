--- tests/check_public.c.orig	2011-07-02 20:20:42 UTC
+++ tests/check_public.c
@@ -30,7 +30,10 @@ static void parse_display_pass(const cha
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
@@ -150,7 +153,7 @@ END_TEST
 
 START_TEST(parse_display_negative)
 {
-	parse_display_fail(0);
+	parse_display_fail(NULL); /* modified by Ashish Shukla. 0 is not NULL in ISO C but in ISO C++ */
 	parse_display_fail("");
 	parse_display_fail(":");
 	parse_display_fail("::");
