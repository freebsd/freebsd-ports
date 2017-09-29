--- altyo_window.vala.orig	2016-04-19 20:55:59 UTC
+++ altyo_window.vala
@@ -2889,7 +2889,7 @@ public class AYObject :Object{
       for (item_it = this.children_removed.last(); item_it != null; item_it = item_it.prev) {
         AYTab tab = item_it.data;
         tab.stop_remove_timer();//disable timer while popup shown
-        string s = ( tab.tbutton.tab_title != null ? tab.tbutton.tab_title : _("index %d").printf(tab.tbutton.tab_index) );
+        string s = ( tab.tbutton.tab_title != null ? tab.tbutton.tab_title : _("index %d").printf((int)tab.tbutton.tab_index) );
         menuitem = new Gtk.MenuItem.with_label ("%d: %s".printf(index,s));
         menuitem.activate.connect(()=>{
           debug("trying to restore tab %s",menuitem.label);
