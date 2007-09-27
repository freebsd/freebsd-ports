--- tag.c.orig
+++ tag.c
@@ -67,13 +67,13 @@ applyrules(Client * c, awesome_config *awesomeconf)
     XClassHint ch = { 0, 0 };
     char *prop;
 
+    XGetClassHint(c->display, c->win, &ch);
     len += a_strlen(ch.res_class) + a_strlen(ch.res_name) + a_strlen(c->name);
 
-    prop = p_new(char, len + 1);
+    prop = p_new(char, len + 3);
 
     /* rule matching */
-    XGetClassHint(c->display, c->win, &ch);
-    snprintf(prop, len + 1, "%s:%s:%s",
+    snprintf(prop, len + 3, "%s:%s:%s",
              ch.res_class ? ch.res_class : "", ch.res_name ? ch.res_name : "", c->name);
     for(i = 0; i < awesomeconf->nrules; i++)
         if(regs[i].propregex && !regexec(regs[i].propregex, prop, 1, &tmp, 0))
