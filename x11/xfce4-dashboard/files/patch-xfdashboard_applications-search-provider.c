--- xfdashboard/applications-search-provider.c.orig	2015-03-04 05:46:06 UTC
+++ xfdashboard/applications-search-provider.c
@@ -318,7 +318,7 @@ static const gchar* _xfdashboard_applica
 /* Overriden virtual function: get_icon */
 static const gchar* _xfdashboard_applications_search_provider_get_icon(XfdashboardSearchProvider *inProvider)
 {
-	return("gtk-missing-image");
+	return("applications-other");
 }
 
 /* Overriden virtual function: get_result_set */
