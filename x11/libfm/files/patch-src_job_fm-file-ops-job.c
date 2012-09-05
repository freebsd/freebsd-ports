--- src/job/fm-file-ops-job.c.orig	2012-09-05 14:01:38.265086278 -0400
+++ src/job/fm-file-ops-job.c	2012-09-05 14:01:52.454076353 -0400
@@ -537,7 +537,7 @@
     }
 
     job->total = fm_path_list_get_length(job->srcs);
-    g_debug("total files to link: %lu", (ulong)job->total);
+    g_debug("total files to link: %lu", (unsigned long)job->total);
 
     fm_file_ops_job_emit_prepared(job);
 
