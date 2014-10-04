diff --git a/kivy/graphics/shader.pyx b/kivy/graphics/shader.pyx
index eab0f42..39c449a 100644
--- kivy/graphics/shader.pyx
+++ kivy/graphics/shader.pyx
@@ -421,6 +421,7 @@ cdef class Shader:
     cdef void bind_vertex_format(self, VertexFormat vertex_format):
         cdef unsigned int i
         cdef vertex_attr_t *attr
+        cdef bytes name
 
         # if the current vertex format used in the shader is the current one, do
         # nothing.
@@ -445,7 +446,8 @@ cdef class Shader:
                 attr = &vertex_format.vattr[i]
                 if attr.per_vertex == 0:
                     continue
-                attr.index = glGetAttribLocation(self.program, <char *><bytes>attr.name)
+                name = <bytes>attr.name
+                attr.index = glGetAttribLocation(self.program, <char *>name)
                 glEnableVertexAttribArray(attr.index)
 
         # save for the next run.
