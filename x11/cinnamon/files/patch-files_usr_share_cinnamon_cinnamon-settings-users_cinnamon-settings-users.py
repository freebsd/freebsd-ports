--- files/usr/share/cinnamon/cinnamon-settings-users/cinnamon-settings-users.py.orig	2025-07-10 21:12:25 UTC
+++ files/usr/share/cinnamon/cinnamon-settings-users/cinnamon-settings-users.py
@@ -255,7 +255,7 @@ class PasswordDialog(Gtk.Dialog):
         self.user.set_password(newpass, "")
         mask = self.group_mask.get_text()
         if "nopasswdlogin" in mask:
-            subprocess.call(["gpasswd", "-d", self.user.get_user_name(), "nopasswdlogin"])
+            subprocess.call(["pw", "groupmod", "nopasswdlogin", "-d", self.user.get_user_name()])
             mask = mask.split(", ")
             mask.remove("nopasswdlogin")
             mask = ", ".join(mask)
@@ -620,7 +620,7 @@ class Module:
             response = dialog.run()
             if response == Gtk.ResponseType.OK:
                 groups = dialog.get_selected_groups()
-                subprocess.call(["usermod", user.get_user_name(), "-G", ",".join(groups)])
+                subprocess.call(["pw", "usermod", user.get_user_name(), "-G", ",".join(groups)])
                 groups.sort()
                 self.groups_label.set_text(", ".join(groups))
             dialog.destroy()
@@ -900,9 +900,9 @@ class Module:
             piter = self.users.append(None, [new_user, pixbuf, description])
             # Add the user to his/her own group and sudo if Administrator was selected
             if dialog.account_type_combo.get_active() == 1:
-                subprocess.call(["usermod", username, "-G", "%s,sudo,nopasswdlogin" % username])
+                subprocess.call(["pw", "usermod", username, "-G", "%s,sudo,nopasswdlogin" % username])
             else:
-                subprocess.call(["usermod", username, "-G", "%s,nopasswdlogin" % username])
+                subprocess.call(["pw", "usermod", username, "-G", "%s,nopasswdlogin" % username])
             self.load_groups()
         dialog.destroy()
 
@@ -947,7 +947,7 @@ class Module:
             d.set_default_response(Gtk.ResponseType.NO)
             r = d.run()
             if r == Gtk.ResponseType.YES:
-                subprocess.call(["groupdel", group])
+                subprocess.call(["pw", "groupdel", group])
                 self.load_groups()
             d.destroy()
 
@@ -955,7 +955,7 @@ class Module:
         dialog = GroupDialog(_("Group Name"), "", self.window)
         response = dialog.run()
         if response == Gtk.ResponseType.OK:
-            subprocess.call(["groupadd", dialog.entry.get_text().lower()])
+            subprocess.call(["pw", "groupadd", dialog.entry.get_text().lower()])
             self.load_groups()
         dialog.destroy()
 
@@ -966,7 +966,7 @@ class Module:
             dialog = GroupDialog(_("Group Name"), group, self.window)
             response = dialog.run()
             if response == Gtk.ResponseType.OK:
-                subprocess.call(["groupmod", group, "-n", dialog.entry.get_text().lower()])
+                subprocess.call(["pw", "groupmod", group, "-l", dialog.entry.get_text().lower()])
                 self.load_groups()
             dialog.destroy()
 
