
$FreeBSD$

--- xbelld.c.orig
+++ xbelld.c
@@ -268,7 +268,7 @@
     u_int   i;
 
     if (!hp->h_size)
-	return NULL;
+	return False;
     i = hp->h_hash(data) % hp->h_size;
     if (!TAILQ_EMPTY(&(hp->h_buckets[i])))
     {
@@ -914,7 +914,7 @@
     close(dfd);
     for (nent = 0, dep = (struct dirent *)dbuf;
 	    (char *)dep - dbuf < nb;
-	    ++nent, (char *)dep+= dep->d_reclen)
+	    ++nent, dep+= dep->d_reclen)
 	;
     _hash_resize(&(_bd.bd_sndhash), nent * 2);
     if (_bd.bd_defsnd)
@@ -924,7 +924,7 @@
     }
     for (dep = (struct dirent *)dbuf;
 	    (char *)dep - dbuf < nb;
-	    (char *)dep+= dep->d_reclen)
+	    dep+= dep->d_reclen)
     {
 	char		    *suf;
 	static const char   *sufs[] = AUDIO_SUFS;
