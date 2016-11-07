Obtained from:

https://cgit.freedesktop.org/xcb/libxcb/commit/src/c_client.py?id=8740a288ca468433141341347aa115b9544891d3

--- src/c_client.py.orig	2016-05-09 16:10:55 UTC
+++ src/c_client.py
@@ -1364,7 +1364,7 @@ def _c_serialize(context, self):
             _c('    unsigned int xcb_align_to = 0;')
         if self.is_switch:
             _c('    unsigned int xcb_padding_offset = %d;',
-	       self.get_align_offset() )
+               self.get_align_offset() )
         prefix = [('_aux', '->', self)]
         aux_ptr = 'xcb_out'
 
@@ -1390,7 +1390,7 @@ def _c_serialize(context, self):
         _c('    unsigned int xcb_align_to = 0;')
         if self.is_switch:
             _c('    unsigned int xcb_padding_offset = %d;',
-	       self.get_align_offset() )
+               self.get_align_offset() )
 
     elif 'sizeof' == context:
         param_names = [p[2] for p in params]
@@ -1930,14 +1930,14 @@ def _c_accessors_list(self, field):
                     # from the request size and divide that by the member size
                     return '(((R->length * 4) - sizeof('+ self.c_type + '))/'+'sizeof('+field.type.member.c_wiretype+'))'
                 else:
-		    # use the accessor to get the start of the list, then
-		    # compute the length of it by subtracting it from
+                    # use the accessor to get the start of the list, then
+                    # compute the length of it by subtracting it from
                     # the adress of the first byte after the end of the
                     # request
-		    after_end_of_request = '(((char*)R) + R->length * 4)'
-		    start_of_list = '%s(R)' % (field.c_accessor_name)
+                    after_end_of_request = '(((char*)R) + R->length * 4)'
+                    start_of_list = '%s(R)' % (field.c_accessor_name)
                     bytesize_of_list = '%s - (char*)(%s)' % (after_end_of_request, start_of_list)
-		    return '(%s) / sizeof(%s)' % (bytesize_of_list, field.type.member.c_wiretype)
+                    return '(%s) / sizeof(%s)' % (bytesize_of_list, field.type.member.c_wiretype)
             else:
                 raise Exception(
                     "lengthless lists with varsized members are not supported. Fieldname '%s'"
