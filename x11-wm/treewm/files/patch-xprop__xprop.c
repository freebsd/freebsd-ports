--- xprop/xprop.c.orig	2002-03-14 21:14:47.000000000 +0900
+++ xprop/xprop.c	2012-09-13 15:21:40.000000000 +0900
@@ -586,7 +586,7 @@
 {
 	if (--_buf_len<0) {
 		_buf_ptr[0]='\0';
-		return;
+		return 0;
 	}
 	_buf_ptr++[0] = c;
 }
@@ -1357,10 +1357,10 @@
     if (id == None) {
 	fprintf (stderr, "%s:  no such property \"%s\"\n",
 		 program_name, propname);
-	return;
+	return 0;
     }
     XDeleteProperty (dpy, w, id);
-    return;
+    return 0;
 }
 
 thunk *Handle_Prop_Requests(argc, argv)
@@ -1514,13 +1514,13 @@
   printf("%s", prop);
   if (!(atom = Parse_Atom(prop, True))) {
 	  printf(":  no such atom on any window.\n");
-	  return;
+	  return 0;
   }
 
   data = Get_Property_Data_And_Type(atom, &length, &type, &size);
   if (!size) {
           puts(":  not found.");
-	  return;
+	  return 0;
   }
 
   if (!notype && type)
@@ -1535,7 +1535,7 @@
   if (fsize!=size && fsize!=0) {
 	printf(": Type mismatch: assumed size %d bits, actual size %d bits.\n",
 	 fsize, size);
-	  return;
+	  return 0;
   }
 
   thunks = Break_Down_Property(data, (int)length, format, size);
