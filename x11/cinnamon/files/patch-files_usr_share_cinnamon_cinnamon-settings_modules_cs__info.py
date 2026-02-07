--- files/usr/share/cinnamon/cinnamon-settings/modules/cs_info.py.orig	2025-07-10 21:17:21 UTC
+++ files/usr/share/cinnamon/cinnamon-settings/modules/cs_info.py
@@ -54,8 +54,11 @@ def getDiskSize():
 def getDiskSize():
     disksize = 0
     try:
-        out = getProcessOut(("lsblk", "--json", "--output", "size", "--bytes", "--nodeps"))
-        jsonobj = loads(''.join(out))
+        out = getProcessOut(("geom", "disk", "list"))
+        jsonobj = {'blockdevices': []}
+        for disk in out:
+            if "Mediasize:" in disk:
+                jsonobj['blockdevices'].append({'size': disk.split()[1]})
     except Exception:
         return _("Unknown size"), False
 
@@ -71,13 +74,12 @@ def getProcInfos():
     # Source: https://github.com/dylanaraps/neofetch/blob/6dd85d67fc0d4ede9248f2df31b2cd554cca6c2f/neofetch#L2163
     cpudetect = ("model name", "Hardware", "Processor", "cpu model", "chip type", "cpu type")
     infos = [
-        ("/proc/cpuinfo", [("cpu_name", cpudetect), ("cpu_siblings", ("siblings",)), ("cpu_cores", ("cpu cores",))]),
-        ("/proc/meminfo", [("mem_total", ("MemTotal",))])
+        ("hw", [("cpu_name", ("hw.model",)), ("cpu_cores", ("hw.ncpu",)), ("mem_total", ("hw.physmem",))]),
     ]
 
     result = {}
     for (proc, pairs) in infos:
-        for line in getProcessOut(("cat", proc)):
+        for line in getProcessOut(("sysctl", proc)):
             for (key, start) in pairs:
                 for item in start:
                     if line.startswith(item):
@@ -122,7 +124,7 @@ def createSystemInfos():
     if memunit == "kB":
         infos.append((_("Memory"), '%.1f %s' % ((float(memsize)/(1024*1024)), _("GiB"))))
     else:
-        infos.append((_("Memory"), procInfos['mem_total']))
+        infos.append((_("Memory"), '%.1f %s' % ((float(memsize)/(1024*1024*1024)), _("GiB"))))
 
     diskSize, multipleDisks = getDiskSize()
     if multipleDisks:
