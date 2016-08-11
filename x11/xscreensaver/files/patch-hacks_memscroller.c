--- hacks/memscroller.c.orig	2016-05-22 01:57:03 UTC
+++ hacks/memscroller.c
@@ -306,13 +306,6 @@ open_file (state *st)
    from earlier days before the advent of virtual memory management."
       -- sbrk(2) man page on BSD systems, as of 1995 or so.
  */
-#ifdef HAVE_SBRK
-# if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)) /* gcc >= 4.2 */
-   /* Don't print "warning: 'sbrk' is deprecated". */
-#  pragma GCC diagnostic ignored "-Wdeprecated-declarations"
-# endif
-#endif
-
 
 static unsigned int
 more_bits (state *st, scroller *sc)
