--- swc/bindings/binding_core_node/src/util.rs.orig	2025-01-23 07:15:43 UTC
+++ swc/bindings/binding_core_node/src/util.rs
@@ -1,5 +1,3 @@
-#![deny(warnings)]
-
 use std::panic::{catch_unwind, AssertUnwindSafe};
 
 use anyhow::{anyhow, Error};
