From a769e80eb4383b4c4a274c5ad192958961122d09 Mon Sep 17 00:00:00 2001
From: Johannes <jnbr_github@jnbr.me>
Date: Thu, 20 Sep 2018 02:04:07 +0200
Subject: [PATCH] Fix build failure on 32-bit machines

Alacritty has some checks in place to make sure that unsafe
code would not fail because of invalid struct sizes. This managed
to successfully catch an incorrect unsafe block on 32-bit machines.

To make sure this block works on both 32-bit and 64-bit systems,
it has been altered to make use of the platform-dependent `usize`
type. This will always make use of correct sizes without having to
rely on conditional compilation.
--- src/grid/storage.rs.orig	2018-09-29 13:21:20 UTC
+++ src/grid/storage.rs
@@ -223,7 +223,7 @@ impl<T> Storage<T> {
     /// instructions. This implementation achieves the swap in only 8 movups
     /// instructions.
     pub fn swap(&mut self, a: usize, b: usize) {
-        assert_eq_size!(Row<T>, [u32; 8]);
+        assert_eq_size!(Row<T>, [usize; 4]);
 
         let a = self.compute_index(a);
         let b = self.compute_index(b);
@@ -232,13 +232,13 @@ impl<T> Storage<T> {
             // Cast to a qword array to opt out of copy restrictions and avoid
             // drop hazards. Byte array is no good here since for whatever
             // reason LLVM won't optimized it.
-            let a_ptr = self.inner.as_mut_ptr().offset(a as isize) as *mut u64;
-            let b_ptr = self.inner.as_mut_ptr().offset(b as isize) as *mut u64;
+            let a_ptr = self.inner.as_mut_ptr().add(a) as *mut usize;
+            let b_ptr = self.inner.as_mut_ptr().add(b) as *mut usize;
 
             // Copy 1 qword at a time
             //
             // The optimizer unrolls this loop and vectorizes it.
-            let mut tmp: u64;
+            let mut tmp: usize;
             for i in 0..4 {
                 tmp = *a_ptr.offset(i);
                 *a_ptr.offset(i) = *b_ptr.offset(i);
