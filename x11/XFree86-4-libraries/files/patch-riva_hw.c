reverse frequency parameter only for Riva128/SGRAM

Index: programs/Xserver/hw/xfree86/drivers/nv/riva_hw.c
===================================================================
RCS file: /home/cvs/X/xc/programs/Xserver/hw/xfree86/drivers/nv/riva_hw.c,v
retrieving revision 1.12
diff -u -u -2 -r1.12 riva_hw.c
--- programs/Xserver/hw/xfree86/drivers/nv/riva_hw.c	2001/02/21 00:42:57	1.12
+++ programs/Xserver/hw/xfree86/drivers/nv/riva_hw.c	2001/03/25 16:20:00
@@ -1780,4 +1780,5 @@
      * Fill in chip configuration.
      */
+    chip->CrystalFreqKHz   = (chip->PEXTDEV[0x00000000/4] & 0x00000020) ? 13500 : 14318;	/* this was reversed, not sure that it is right this way either (HCS) */
     if (chip->PFB[0x00000000/4] & 0x00000020)
     {
@@ -1813,4 +1814,5 @@
          * SGRAM 128.
          */
+        chip->CrystalFreqKHz   = (chip->PEXTDEV[0x00000000/4] & 0x00000020) ? 14318 : 13500;
         chip->RamBandwidthKBytesPerSec = 1000000;
         switch (chip->PFB[0x00000000/4] & 0x00000003)
@@ -1827,5 +1829,4 @@
         }
     }        
-    chip->CrystalFreqKHz   = (chip->PEXTDEV[0x00000000/4] & 0x00000020) ? 13500 : 14318;	/* this was reversed, not sure that it is right this way either (HCS) */
     chip->CURSOR           = &(chip->PRAMIN[0x00008000/4 - 0x0800/4]);
     chip->CURSORPOS        = &(chip->PRAMDAC[0x0300/4]);
