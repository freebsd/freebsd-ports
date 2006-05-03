--- src/yelp-search-pager.c.orig	Tue May  2 19:10:03 2006
+++ src/yelp-search-pager.c	Tue May  2 18:59:36 2006
@@ -1413,7 +1413,7 @@ process_man_result (YelpSearchPager *pag
 	after = strstr (before, "(");
 	tmp = after;	
 
-	while (!g_ascii_isspace(*tmp))
+	while (g_ascii_isspace(*tmp))
 	    tmp--;
 
 	title = g_strndup (before, tmp-before);
