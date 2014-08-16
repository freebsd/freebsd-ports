--- xbelld.c.orig	2002-10-26 20:28:36.000000000 -0400
+++ xbelld.c	2014-08-16 14:07:14.000000000 -0400
@@ -60,8 +60,7 @@
 #include    <dirent.h>
 
 #ifndef lint
-static const char rcsid[] =
-	"$Id: xbelld.c,v 1.7 2002/10/27 00:28:36 sethk Exp $";
+__RCSID("$Id: xbelld.c,v 1.7 2002/10/27 00:28:36 sethk Exp $");
 #endif /* !lint */
 
 #define XskRFilename	"XskRFilename"
@@ -268,7 +267,7 @@
     u_int   i;
 
     if (!hp->h_size)
-	return NULL;
+	return False;
     i = hp->h_hash(data) % hp->h_size;
     if (!TAILQ_EMPTY(&(hp->h_buckets[i])))
     {
@@ -914,7 +913,7 @@
     close(dfd);
     for (nent = 0, dep = (struct dirent *)dbuf;
 	    (char *)dep - dbuf < nb;
-	    ++nent, (char *)dep+= dep->d_reclen)
+	    ++nent, dep+= dep->d_reclen)
 	;
     _hash_resize(&(_bd.bd_sndhash), nent * 2);
     if (_bd.bd_defsnd)
@@ -924,7 +923,7 @@
     }
     for (dep = (struct dirent *)dbuf;
 	    (char *)dep - dbuf < nb;
-	    (char *)dep+= dep->d_reclen)
+	    dep+= dep->d_reclen)
     {
 	char		    *suf;
 	static const char   *sufs[] = AUDIO_SUFS;
