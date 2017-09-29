--- altyo_settings.vala.orig	2016-04-19 20:55:59 UTC
+++ altyo_settings.vala
@@ -701,7 +701,11 @@ public class AYSettings : AYTab{
         view.get_cursor(out path,out s_column);
         if(store.get_iter(out iter,path))
         if(!store.iter_has_child(iter)){
+#if VALA_0_36
+          store.remove(ref iter);
+#else
           store.remove(iter);
+#endif
           if(store.get_iter(out iter,path))
             view.set_cursor(path,null,false);
           else if(path.prev())
@@ -735,7 +739,11 @@ public class AYSettings : AYTab{
         view.get_cursor(out path,out s_column);
         if(store.get_iter(out iter,path))
         if(!store.iter_has_child(iter)){
+#if VALA_0_36
+          store.remove(ref iter);
+#else
           store.remove(iter);
+#endif
           if(store.get_iter(out iter,path))
             view.set_cursor(path,null,false);
           else if(path.prev())
@@ -769,7 +777,11 @@ public class AYSettings : AYTab{
         view.get_cursor(out path,out s_column);
         if(store.get_iter(out iter,path))
         if(!store.iter_has_child(iter)){
+#if VALA_0_36
+          store.remove(ref iter);
+#else
           store.remove(iter);
+#endif
           if(store.get_iter(out iter,path))
             view.set_cursor(path,null,false);
           else if(path.prev())
@@ -956,7 +968,7 @@ public class AYSettings : AYTab{
     string msg="";
     uint line,pos;
     if(!this.check_css(B.buffer.text,ref S,out line,out pos)){
-      msg=_("in line %d  at position %d error:%s").printf(line,pos,S);
+      msg=_("in line %d  at position %d error:%s").printf((int)line,(int)pos,S);
       debug("on_check_css_button_activate %s",msg);
       TextIter where;
       B.buffer.get_iter_at_line_offset(out where,(int)line,(int)pos);
@@ -1606,7 +1618,7 @@ public class AYSettings : AYTab{
               string S="";
               uint line,pos;
               if(!this.check_css(s,ref S,out line,out pos)){
-                string msg=_("New style will not be saved!\nin line %d  at position %d\nerror:%s").printf(line,pos,S);
+                string msg=_("New style will not be saved!\nin line %d  at position %d\nerror:%s").printf((int)line,(int)pos,S);
                 debug("on config apply css error %s",msg);
                 this.ayobject.main_window.show_message_box(_("AltYo CSS style error"),msg);
               }else{//looks good
