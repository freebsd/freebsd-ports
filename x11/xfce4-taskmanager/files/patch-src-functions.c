--- src/functions.c.orig	Tue Feb  1 23:32:27 2005
+++ src/functions.c	Tue May 24 21:57:39 2005
@@ -41,13 +41,13 @@
 {
 	/* markes all tasks to "not checked" */
 	gint i;
+	DIR *dir;
+	struct dirent *dir_entry;
 	
 	for(i = 0; i < task_count; i++)
 		all_tasks[i].checked = FALSE;
 	
 	/* load the current taskdetails */
-	DIR *dir;
-	struct dirent *dir_entry;
 
 	if((dir = opendir("/proc")) == NULL)
 		printf("Error: couldn't load the directory\n");
@@ -56,18 +56,20 @@
 	{
 		if(atoi(dir_entry->d_name) != 0)
 		{
-			FILE *task_file;
-			gchar task_file_name[256] = "/proc/";
-			g_strlcat(task_file_name,dir_entry->d_name, 256);
-			g_strlcat(task_file_name,"/status", 256);
-		
 			gchar buffer[256];
 			gint line_count = 0;
 			struct task task;
 			struct passwd *passwdp;
 		
+			FILE *task_file;
+			gchar task_file_name[256] = "/proc/";
+			g_strlcat(task_file_name,dir_entry->d_name, 256);
+			g_strlcat(task_file_name,"/status", 256);
+		
 			if((task_file = fopen(task_file_name,"r")) != NULL)
 			{
+				gboolean new_task = TRUE;
+				
 				while(fgets(buffer, 256, task_file) != NULL)
 				{
 					if(line_count == 0)
@@ -89,8 +91,6 @@
 				fclose(task_file);
 				
 				/* check if task is new and marks the task that its checked*/
-				gboolean new_task = TRUE;
-				
 				for(i = 0; i < task_count; i++)
 				{
 					if(strcmp(all_tasks[i].pid,task.pid) == 0)
