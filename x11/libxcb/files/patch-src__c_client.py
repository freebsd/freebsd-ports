--- src/c_client.py.orig	2013-11-11 14:30:55.471622828 +0100
+++ src/c_client.py	2013-11-11 14:32:05.334624142 +0100
@@ -1133,11 +1133,11 @@
             _c('    %s *xcb_out = *_buffer;', self.c_type)
             _c('    unsigned int xcb_out_pad = -sizeof(%s) & 3;', self.c_type)
             _c('    unsigned int xcb_buffer_len = sizeof(%s) + xcb_out_pad;', self.c_type)
-            _c('    unsigned int xcb_align_to;')
+            _c('    unsigned int xcb_align_to = 0;')
         else:
             _c('    char *xcb_out = *_buffer;')
             _c('    unsigned int xcb_buffer_len = 0;')
-            _c('    unsigned int xcb_align_to;')
+            _c('    unsigned int xcb_align_to = 0;')
         prefix = [('_aux', '->', self)]
         aux_ptr = 'xcb_out'
 
@@ -1160,7 +1160,7 @@
         _c('    unsigned int xcb_buffer_len = 0;')
         _c('    unsigned int xcb_block_len = 0;')
         _c('    unsigned int xcb_pad = 0;')
-        _c('    unsigned int xcb_align_to;')
+        _c('    unsigned int xcb_align_to = 0;')
 
     elif 'sizeof' == context:
         param_names = [p[2] for p in params]
@@ -1205,7 +1205,7 @@
             _c('    unsigned int xcb_buffer_len = 0;')
             _c('    unsigned int xcb_block_len = 0;')
             _c('    unsigned int xcb_pad = 0;')        
-            _c('    unsigned int xcb_align_to;')
+            _c('    unsigned int xcb_align_to = 0;')
 
     _c('')
     for t in temp_vars:
