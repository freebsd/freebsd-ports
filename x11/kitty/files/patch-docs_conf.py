--- docs/conf.py.orig	2023-08-26 07:33:11 UTC
+++ docs/conf.py
@@ -177,7 +177,7 @@ manpages_url = 'https://man7.org/linux/man-pages/man{s
 # (source start file, name, description, authors, manual section).
 man_pages = [
     ('invocation', 'kitty', 'kitty Documentation', [author], 1),
-    ('conf', 'kitty.conf', 'kitty.conf Documentation', [author], 5)
+    ('conf', 'kitty.conf', 'kitty terminal emulator configuration file', [author], 5)
 ]
 
 
@@ -207,18 +207,10 @@ def commit_role(
     name: str, rawtext: str, text: str, lineno: int, inliner: Any, options: Any = {}, content: Any = []
 ) -> Tuple[List[nodes.reference], List[nodes.problematic]]:
     ' Link to a github commit '
-    try:
-        commit_id = subprocess.check_output(
-            f'git rev-list --max-count=1 --skip=# {text}'.split()).decode('utf-8').strip()
-    except Exception:
-        msg = inliner.reporter.error(
-            f'GitHub commit id "{text}" not recognized.', line=lineno)
-        prb = inliner.problematic(rawtext, rawtext, msg)
-        return [prb], [msg]
+    commit_id = text
     url = f'https://github.com/kovidgoyal/kitty/commit/{commit_id}'
     set_classes(options)
-    short_id = subprocess.check_output(
-        f'git rev-list --max-count=1 --abbrev-commit --skip=# {commit_id}'.split()).decode('utf-8').strip()
+    short_id = text[:9]
     node = nodes.reference(rawtext, f'commit: {short_id}', refuri=url, **options)
     return [node], []
 # }}}
