--- data/scripts/pekwm_themeset.sh.in.orig	2008-08-07 01:54:14.000000000 +0200
+++ data/scripts/pekwm_themeset.sh.in	2008-08-07 01:55:00.000000000 +0200
@@ -46,7 +46,8 @@
         fi
 
         # Change theme
-        sed -e "s/^\([^#]*\)Theme\ =\ \"[^\"]*\"/\\1Theme\ =\ \"${theme}\"/i" "${PEKWM_CONFIG_FILE}" > "${tmp_file}"
+        gsed -e "s/^\([^#]*\)Theme\ =\ \"[^\"]*\"/\\1Theme\ =\ \"${theme}\"/i" "${PEKWM_CONFIG_FILE}" > "${tmp_file}"
+        cp "${PEKWM_CONFIG_FILE}" "${PEKWM_CONFIG_FILE}".bak
         mv "${tmp_file}" "${PEKWM_CONFIG_FILE}"
 
         # Reload pekwm
