diff --git a/meson.build b/meson.build
index 94973255d7af4020b049c1e533b2438409514f03..9ff17117a9f6c79bb50362d6db6507ba56c20136 100644
--- meson.build
+++ meson.build
@@ -83,6 +83,10 @@ if get_option('coverity')
 	config_h.set('_Float64x', 'long')
 endif
 
+if cc.has_header_symbol('dirent.h', 'versionsort', prefix : prefix)
+	config_h.set('HAVE_VERSIONSORT', '1')
+endif
+
 # Dependencies
 pkgconfig = import('pkgconfig')
 dep_udev = dependency('libudev')
diff --git a/src/libinput-versionsort.h b/src/libinput-versionsort.h
new file mode 100644
index 0000000000000000000000000000000000000000..356ec8da2f56ccedefb4f30cbeb353a1140e175a
--- /dev/null
+++ src/libinput-versionsort.h
@@ -0,0 +1,71 @@
+#pragma once
+
+#include "config.h"
+
+#ifndef HAVE_VERSIONSORT
+
+/* Copyright © 2005-2014 Rich Felker, et al.
+ *
+ * Permission is hereby granted, free of charge, to any person obtaining
+ * a copy of this software and associated documentation files (the
+ * "Software"), to deal in the Software without restriction, including
+ * without limitation the rights to use, copy, modify, merge, publish,
+ * distribute, sublicense, and/or sell copies of the Software, and to
+ * permit persons to whom the Software is furnished to do so, subject to
+ * the following conditions:
+ *
+ * The above copyright notice and this permission notice shall be
+ * included in all copies or substantial portions of the Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
+ * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
+ * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
+ * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
+ * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
+ * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
+ * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
+ */
+
+#include <ctype.h>
+#include <string.h>
+#include <dirent.h>
+
+static int
+strverscmp(const char *l0, const char *r0)
+{
+	const unsigned char *l = (const void *)l0;
+	const unsigned char *r = (const void *)r0;
+	size_t i, dp, j;
+	int z = 1;
+
+	/* Find maximal matching prefix and track its maximal digit
+	 * suffix and whether those digits are all zeros. */
+	for (dp=i=0; l[i]==r[i]; i++) {
+		int c = l[i];
+		if (!c) return 0;
+		if (!isdigit(c)) dp=i+1, z=1;
+		else if (c!='0') z=0;
+	}
+
+	if (l[dp]!='0' && r[dp]!='0') {
+		/* If we're not looking at a digit sequence that began
+		 * with a zero, longest digit string is greater. */
+		for (j=i; isdigit(l[j]); j++)
+			if (!isdigit(r[j])) return 1;
+		if (isdigit(r[j])) return -1;
+	} else if (z && dp<i && (isdigit(l[i]) || isdigit(r[i]))) {
+		/* Otherwise, if common prefix of digit sequence is
+		 * all zeros, digits order less than non-digits. */
+		return (unsigned char)(l[i]-'0') - (unsigned char)(r[i]-'0');
+	}
+
+	return l[i] - r[i];
+}
+
+static int
+versionsort(const struct dirent **a, const struct dirent **b)
+{
+	return strverscmp((*a)->d_name, (*b)->d_name);
+}
+
+#endif
diff --git a/tools/libinput-record.c b/tools/libinput-record.c
index 50b6ee8512af6dff4badd95ce8546a346e4701c0..169947df0160f862a8a4c7bffe255909be572d20 100644
--- tools/libinput-record.c
+++ tools/libinput-record.c
@@ -40,6 +40,7 @@
 #include <signal.h>
 #include <stdbool.h>
 
+#include "libinput-versionsort.h"
 #include "libinput-util.h"
 #include "libinput-version.h"
 #include "libinput-git-version.h"
