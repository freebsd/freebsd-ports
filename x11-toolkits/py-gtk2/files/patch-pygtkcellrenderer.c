--- ./gtk/pygtkcellrenderer.c.orig	Sat Jul 20 07:37:29 2002
+++ ./gtk/pygtkcellrenderer.c	Fri Nov  8 21:01:20 2002
@@ -94,6 +94,7 @@
 				      gint            *height)
 {
     PyObject *self, *py_ret, *py_widget, *py_cell_area;
+    gint my_x, my_y, my_width, my_height;
 
     g_return_if_fail(PYGTK_IS_GENERIC_CELL_RENDERER (cell));
 
@@ -117,13 +118,26 @@
     Py_DECREF(py_widget);
     Py_DECREF(py_cell_area);
 
-    if (!PyArg_ParseTuple(py_ret, "iiii", x_offset, y_offset, width, height)) {
+    if (!PyArg_ParseTuple(py_ret, "iiii",
+			  &my_x, &my_y, &my_width, &my_height)) {
 	PyErr_Clear();
 	Py_DECREF(py_ret);
 	g_warning("could not parse return value of get_size() method.  "
 		  "Should be of form (x_offset, y_offset, width, height)");
 	return;
     }
+
+    if (x_offset)
+	*x_offset = my_x;
+
+    if (y_offset)
+	*y_offset = my_y;
+
+    if (width)
+	*width = my_width;
+
+    if (height)
+	*height = my_height;
     /* success */
 }
 
