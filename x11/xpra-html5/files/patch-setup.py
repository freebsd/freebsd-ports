--- setup.py.orig	2024-01-31 12:10:11 UTC
+++ setup.py
@@ -50,7 +50,7 @@ def get_output_line(cmd: str) -> str:
     out, _ = proc.communicate()
     if proc.returncode != 0:
         print(f"Error: {cmd} returned {proc.returncode}")
-        return None
+        return ""
     return out.splitlines()[0]
 
 
@@ -316,7 +316,7 @@ def install_html5(root="/", install_dir="/usr/share/xp
                         jar = yuicompressor.get_jar_filename()
                         java_cmd = os.environ.get("JAVA", "java")
                         minify_cmd = [java_cmd, "-jar", jar]
-                    except OSError:
+                    except:
                         minify_cmd = ["yuicompressor"]
                     minify_cmd += [
                         fsrc,
