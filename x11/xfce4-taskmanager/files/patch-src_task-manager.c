--- src/task-manager.c.orig	2019-12-09 09:12:44 UTC
+++ src/task-manager.c
@@ -432,10 +432,12 @@ xtm_task_manager_update_model (XtmTaskManager *manager
 		gtk_tree_model_get (manager->model, &cur_iter, XTM_PTV_COLUMN_CPU_STR, &cpu_str, XTM_PTV_COLUMN_TIMESTAMP, &old_timestamp, XTM_PTV_COLUMN_PID, &pid, -1);
 		found = (g_strcmp0 (cpu_str, "-") == 0);
 		g_free (cpu_str);
-		if (found && (timestamp - old_timestamp) > TIMESTAMP_DELTA)
+		if (found)
 		{
-			G_DEBUG_FMT ("Remove old task %d", pid);
-			model_remove_tree_iter (manager->model, &cur_iter);
+			if ((timestamp - old_timestamp) > TIMESTAMP_DELTA) {
+				G_DEBUG_FMT ("Remove old task %d", pid);
+				model_remove_tree_iter (manager->model, &cur_iter);
+			}
 			continue;
 		}
 
