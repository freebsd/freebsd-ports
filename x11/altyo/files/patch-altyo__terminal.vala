--- altyo_terminal.vala.orig	2016-04-19 20:55:59 UTC
+++ altyo_terminal.vala
@@ -50,7 +50,7 @@ public class TildaAuth:Object{
     //string[] commands={};
     //commands=command.split(",");
     this.command=command;
-    if( GLib.Regex.match_simple("^ *ssh *(,.*)?$",this.command,RegexCompileFlags.CASELESS,0) )
+    if( GLib.Regex.match_simple("^ *ssh *(,.*)?$",this.command,GLib.RegexCompileFlags.CASELESS,0) )
       this.type="ssh";
     else
       this.type="unknown";
@@ -248,26 +248,26 @@ public class VTToggleButton : Gtk.Button
               debug(" RegexEvalCallback %s %s %d",result.str,match_info.fetch(0),match_info.get_match_count());
               GLib.Regex grx;
 
-              if(!done[0] && Regex.match_simple(".*_REPLACE_.*",this.tab_title_regex[i+1])){
+              if(!done[0] && GLib.Regex.match_simple(".*_REPLACE_.*",this.tab_title_regex[i+1])){
                 //done[0]=true;//replace is allowed repeatedly
                 grx = new GLib.Regex(GLib.Regex.escape_string("_REPLACE_"));
                 result.append(grx.replace_literal(this.tab_title_regex[i+1],-1, 0, match_info.fetch(match_info.get_match_count()-1)) );
                 return true;//stop
               }else
-              if(!done[1] && Regex.match_simple(".*_USER_.*",this.tab_title_regex[i+1])){
+              if(!done[1] && GLib.Regex.match_simple(".*_USER_.*",this.tab_title_regex[i+1])){
                 done[1]=true;
                 grx = new GLib.Regex(GLib.Regex.escape_string("_USER_"));
                 result.append(grx.replace_literal(this.tab_title_regex[i+1],-1, 0, match_info.fetch(match_info.get_match_count()-1)) );
                 return true;//stop
               }else
-              if(!done[2] && Regex.match_simple(".*_HOSTNAME_.*",this.tab_title_regex[i+1])){
+              if(!done[2] && GLib.Regex.match_simple(".*_HOSTNAME_.*",this.tab_title_regex[i+1])){
                 done[2]=true;
                 grx = new GLib.Regex(GLib.Regex.escape_string("_HOSTNAME_"));
                 result.append(grx.replace_literal(this.tab_title_regex[i+1],-1, 0, match_info.fetch(match_info.get_match_count()-1)) );
                 this.host_name=match_info.fetch(match_info.get_match_count()-1);
                 return true;//stop
               }else
-              if(!done[3] && Regex.match_simple(".*_PATH_.*",this.tab_title_regex[i+1])){
+              if(!done[3] && GLib.Regex.match_simple(".*_PATH_.*",this.tab_title_regex[i+1])){
                 done[3]=true;
                 grx = new GLib.Regex(GLib.Regex.escape_string("_PATH_"));
                 result.append(grx.replace_literal(this.tab_title_regex[i+1],-1, 0, match_info.fetch(match_info.get_match_count()-1)) );
@@ -802,7 +802,7 @@ public class VTTerminal : AYTab{
         (arg == "GDK_CORE_DEVICE_EVENTS" && this.my_conf.get_boolean("workaround_if_focuslost",false) ) ){
         continue;//skip
       }else
-      if( !GLib.Regex.match_simple(term_exclude_vars,arg,RegexCompileFlags.CASELESS,0) ){
+      if( !GLib.Regex.match_simple(term_exclude_vars,arg,GLib.RegexCompileFlags.CASELESS,0) ){
         unowned string val=GLib.Environment.get_variable(arg);
         string s="%s=%s".printf(arg,(val!=null?val:""));
         envv+=s;
@@ -1056,7 +1056,7 @@ public class VTTerminal : AYTab{
       this.match_tags.steal_all();
       debug("url_regexps=%d",url_regexps.length);
       for(int j=0;j<url_regexps.length-1;j+=2){
-        var key=this.vte_term.match_add_gregex((new Regex (url_regexps[j])),0);
+        var key=this.vte_term.match_add_gregex((new GLib.Regex (url_regexps[j])),0);
         debug("match_add_gregex %d",key);
         if(!this.match_tags.lookup_extended(key,null,null))
           this.match_tags.insert(key,url_regexps[j+1]);
@@ -1616,7 +1616,7 @@ public class VTTerminal : AYTab{
         //Password:
         vte_text=vte_text.strip();
         debug("expect=%s get '%s'",expect_string,vte_text);
-        if(GLib.Regex.match_simple(".*"+expect_string+".*",vte_text,RegexCompileFlags.CASELESS,0)){
+        if(GLib.Regex.match_simple(".*"+expect_string+".*",vte_text,GLib.RegexCompileFlags.CASELESS,0)){
           this.vte_term.feed_child(paste,paste.length);
           if(cb!=null) cb();
           return false;
