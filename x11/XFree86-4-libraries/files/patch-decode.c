--- extras/x86emu/src/x86emu/decode.c.orig	Sat Jan  6 20:19:03 2001
+++ extras/x86emu/src/x86emu/decode.c	Mon May 20 02:02:34 2002
@@ -734,6 +734,10 @@
 {
 	unsigned offset;
 
+	if (M.x86.mode & SYSMODE_PREFIX_ADDR) {
+		u32* rp = decode_rm_long_register(rm);
+		return (*rp);
+	}
 	switch (rm) {
       case 0:
 		DECODE_PRINTF("[BX+SI]");
@@ -782,6 +786,10 @@
 	int rm)
 {
 	int displacement = (s8)fetch_byte_imm();
+	if (M.x86.mode & SYSMODE_PREFIX_ADDR) {
+		u32* rp = decode_rm_long_register(rm);
+		return (*rp + displacement);
+	}
 	switch (rm) {
       case 0:
 		DECODE_PRINTF2("%d[BX+SI]", displacement);
@@ -830,6 +838,10 @@
 	int rm)
 {
 	unsigned displacement = (u16)fetch_word_imm();
+	if (M.x86.mode & SYSMODE_PREFIX_ADDR) {
+		u32* rp = decode_rm_long_register(rm);
+		return (*rp + displacement);
+	}
 	switch (rm) {
       case 0:
 		DECODE_PRINTF2("%04x[BX+SI]", displacement);
