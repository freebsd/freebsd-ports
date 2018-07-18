--- xglock/xglock.c.orig	2017-01-06 05:18:57 UTC
+++ xglock/xglock.c
@@ -1,3 +1,27 @@
+Assertion failed: (SE.DT.dominates(Ret, &*BIP)), function ReuseOrCreateCast, file /usr/src/contrib/llvm/lib/Analysis/ScalarEvolutionExpander.cpp, line 83.
+cc: error: unable to execute command: Abort trap (core dumped)
+cc: error: clang frontend command failed due to signal (use -v to see invocation)
+
+--- xglock/xglock.c.orig	2018-07-08 11:29:53 UTC
++++ xglock/xglock.c
+@@ -1489,7 +1489,7 @@ static void
+ create_boolOptions_buttons(GtkScrolledWindow *parent)
+ {
+     gint         i;
+-    gpointer     iptr = 0;
++    guint        iptr = 0;
+     GtkWidget   *box0;
+     GtkWidget   *box1;
+     GtkWidget   *box2;
+@@ -1514,7 +1514,7 @@ create_boolOptions_buttons(GtkScrolledWindow *parent)
+         gtk_box_pack_start(GTK_BOX(i%2 ? box1 : box2), button, TRUE, TRUE, 0);
+         gtk_signal_connect(GTK_OBJECT(button), "clicked",
+                            (GtkSignalFunc) bool_option_clicked_cb,
+-                           iptr++);
++                           GUINT_TO_POINTER(iptr++));
+         gtk_widget_show(button);
+     }
+ }
 /*-
  * xglock.c - main file for xglock, the GTK+ gui interface to xlock.
  *
