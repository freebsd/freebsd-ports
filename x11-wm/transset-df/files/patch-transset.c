--- /transSet.c	2007-08-17 18:02:34.000000000 +0200
+++ transSet.c	2007-08-17 18:03:28.000000000 +0200
@@ -39,6 +39,8 @@
   fprintf(stderr,
 	  "    -p, --point          select the window currently under the cursor\n");
   fprintf(stderr,
+	  "    -a, --actual         select the actual window\n");
+  fprintf(stderr,
 	  "    -n, --name NAME      select by name, NAME is matched as regular expression\n");
   fprintf(stderr,
 	  "    --no-regex           don't use regular expression for matching name\n");
@@ -85,6 +87,15 @@
 		return child;
 }
 
+/* returns the actual window */
+Window get_actual_window(Display *dpy)
+{
+    int i;
+    Window w;
+
+    XGetInputFocus(dpy, &w, &i);
+    return get_top_window(dpy, w);
+}
 
 /* nothing fancy */
 int main(int argc, char **argv)
@@ -109,6 +120,7 @@
     {"toggle",0,NULL,'t'},
     {"help",0,NULL,'h'},
     {"point",0,NULL,'p'},
+    {"actual",0,NULL,'a'},
     {"click",0,NULL,'c'},
     {"id",1,NULL,'i'},
     {"name",1,NULL,'n'},
@@ -131,7 +143,7 @@
   Setup_Display_And_Screen(&argc, argv);
 
 	/* parse arguments */
-  while ((o = getopt_long(argc, argv, "thpci:n:vVm:x:123",long_options,&options_index)) != -1)
+  while ((o = getopt_long(argc, argv, "thapci:n:vVm:x:123",long_options,&options_index)) != -1)
     {
       switch (o) {
       case 't':
@@ -156,6 +168,9 @@
 				namestr = optarg;
 				select_method=3;
 			break;
+      case 'a':
+				select_method=4;
+			break;
       case '1':
 				flag_increase=1;
 			break;
@@ -228,6 +243,8 @@
 		target_win = get_top_window(dpy,target_win);
 		if(flag_verbose) printf("found 0x%x\n",(unsigned int)target_win);
 		
+  } else if(select_method==4) {
+     target_win = get_actual_window(dpy);
   } else {
     /* grab mouse and return window that is next clicked */
     target_win = Select_Window(dpy);
