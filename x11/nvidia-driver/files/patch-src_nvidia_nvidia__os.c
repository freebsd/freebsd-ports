- vbe framebuffer mode adjustment that enables switch back and forth to the black terminal
- from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=213912#c17

--- src/nvidia/nvidia_os.c.orig	2022-12-27 22:31:44 UTC
+++ src/nvidia/nvidia_os.c
@@ -789,6 +789,28 @@ void NV_API_CALL os_get_screen_info(
             *pFbPitch = efifb->fb_stride * (bpp / NBBY);
             return;
         }
+
+        const struct vbe_fb *vbefb =
+            (const struct vbe_fb *)preload_search_info(kmdp, MODINFO_METADATA |
+                                                             MODINFOMD_VBE_FB);
+
+        /* Make sure base address is mapped to GPU BAR */
+        if ((vbefb != NULL) &&
+            ((vbefb->fb_addr == consoleBar1Address) ||
+             (vbefb->fb_addr == consoleBar2Address)))
+        {
+            int depth = fls(vbefb->fb_mask_red | vbefb->fb_mask_green |
+                            vbefb->fb_mask_blue | vbefb->fb_mask_reserved);
+            int bpp = roundup2(depth, NBBY);
+
+            *pPhysicalAddress = vbefb->fb_addr;
+            *pFbWidth = vbefb->fb_width;
+            *pFbHeight = vbefb->fb_height;
+            *pFbDepth = depth;
+            /* fb_stride is in pixels. Convert to bytes */
+            *pFbPitch = vbefb->fb_stride * (bpp / NBBY);
+            return;
+        }
     }
     {
         const sc_softc_t *sc = sc_get_softc(0, SC_KERNEL_CONSOLE);
