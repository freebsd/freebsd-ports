--- libAfterBase/selfdiag.c.orig	2022-07-08 13:20:45.173997000 -0700
+++ libAfterBase/selfdiag.c	2022-07-08 13:22:14.990203000 -0700
@@ -89,6 +89,11 @@
 proc_tables   _ptabs;
 char         *_elf_start = (char *)0x08048000;
 
+#ifdef HAVE_ELF_H
+# if (defined(HAVE_ELF32_DYN_D_TAG) || defined(HAVE_ELF64_DYN_D_TAG)) && HAVE_DECL_ELFW
+extern ElfW(Dyn) _DYNAMIC[];
+#endif
+#endif
 
 void
 get_proc_tables (proc_tables * ptabs)
