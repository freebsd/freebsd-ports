--- pixman/pixman-arm-simd-asm.S.orig	2024-10-18 09:27:57 UTC
+++ pixman/pixman-arm-simd-asm.S
@@ -818,13 +818,13 @@ generate_composite_function \
 .macro over_white_8888_8888_ca_1pixel_tail
         mvn     TMP0, WK1
         teq     WK1, WK1, asr #32
-        bne     01f
-        bcc     03f
+        bne     1f
+        bcc     3f
         mov     WK3, WK1
-        b       02f
-01:     over_white_8888_8888_ca_combine WK1, WK3
-02:     pixst   , 4, 3, DST
-03:
+        b       2f
+1:      over_white_8888_8888_ca_combine WK1, WK3
+2:      pixst   , 4, 3, DST
+3:
 .endm
 
 .macro over_white_8888_8888_ca_2pixels_head
@@ -835,21 +835,21 @@ generate_composite_function \
         pixld   , 8, 3, DST
         mvn     TMP0, WK1
         teq     WK1, WK1, asr #32
-        bne     01f
+        bne     1f
         movcs   WK3, WK1
-        bcs     02f
+        bcs     2f
         teq     WK2, #0
-        beq     05f
-        b       02f
-01:     over_white_8888_8888_ca_combine WK1, WK3
-02:     mvn     TMP0, WK2
+        beq     5f
+        b       2f
+1:      over_white_8888_8888_ca_combine WK1, WK3
+2:      mvn     TMP0, WK2
         teq     WK2, WK2, asr #32
-        bne     03f
+        bne     3f
         movcs   WK4, WK2
-        b       04f
-03:     over_white_8888_8888_ca_combine WK2, WK4
-04:     pixst   , 8, 3, DST
-05:
+        b       4f
+3:     over_white_8888_8888_ca_combine WK2, WK4
+4:     pixst   , 8, 3, DST
+5:
 .endm
 
 .macro over_white_8888_8888_ca_process_head  cond, numbytes, firstreg, unaligned_src, unaligned_mask, preload
@@ -1065,9 +1065,9 @@ generate_composite_function \
   .if offset != 0
         ldrb    ORIG_W, [SRC, #offset]
   .endif
-        beq     01f
+        beq     1f
         teq     STRIDE_M, #0xFF
-        beq     02f
+        beq     2f
  .endif
         uxtb16  SCRATCH, d                 /* rb_dest */
         uxtb16  d, d, ror #8               /* ag_dest */
@@ -1077,13 +1077,13 @@ generate_composite_function \
         uxtab16 d, d, d, ror #8
         mov     SCRATCH, SCRATCH, ror #8
         sel     d, SCRATCH, d
-        b       02f
+        b       2f
  .if offset == 0
 48:     /* Last mov d,#0 of the set - used as part of shortcut for
          * source values all 0 */
  .endif
-01:     mov     d, #0
-02:
+1:     mov     d, #0
+2:
 .endm
 
 .macro in_reverse_8888_8888_tail  numbytes, reg1, reg2, reg3, reg4
