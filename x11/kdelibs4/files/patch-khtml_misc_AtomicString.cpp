Backport of:

From 7ed8ac1ae23a31d2eb227ffa15d68b2beaf8f37d Mon Sep 17 00:00:00 2001
From: Milian Wolff <mail@milianw.de>
Date: Wed, 26 Feb 2014 22:37:29 +0100
Subject: [PATCH] Fix compiler error when using clang:

src/misc/AtomicString.cpp:175:28: error: non-constant-expression
 cannot be narrowed from type 'int' to 'unsigned int' in initializer
 list [-Wc++11-narrowing]
    UCharBuffer buf = { s, length };
                           ^~~~~~
src/misc/AtomicString.cpp:175:28: note: override this message by
 inserting an explicit cast
    UCharBuffer buf = { s, length };
                           ^~~~~~
                           static_cast<unsigned int>( )

REVIEW: 116541

--- khtml/misc/AtomicString.cpp.orig	2018-01-07 11:32:56 UTC
+++ khtml/misc/AtomicString.cpp
@@ -160,7 +160,7 @@ DOMStringImpl* AtomicString::add(const QChar* s, int l
         return DOMStringImpl::empty();
    
     init();
-    UCharBuffer buf = { s, length }; 
+    UCharBuffer buf = { s, static_cast<uint>(length) }; 
     std::pair<HashSet<DOMStringImpl*>::iterator, bool> addResult = stringTable->add<UCharBuffer, UCharBufferTranslator>(buf);
     if (!addResult.second)
         return *addResult.first;
@@ -180,7 +180,7 @@ DOMStringImpl* AtomicString::add(const QChar* s)
         return DOMStringImpl::empty();
 
     init();
-    UCharBuffer buf = {s, length}; 
+    UCharBuffer buf = {s, static_cast<uint>(length) }; 
     std::pair<HashSet<DOMStringImpl*>::iterator, bool> addResult = stringTable->add<UCharBuffer, UCharBufferTranslator>(buf);
     if (!addResult.second)
         return *addResult.first;
