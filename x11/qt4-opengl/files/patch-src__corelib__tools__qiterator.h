commit 5210d47aa66214e3cb16f394d0510a91f770c1b1
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Mon Jul 16 23:39:07 2012 -0300

    Only forward-declare some std classes if QT_NO_STL is defined.
    
    If that is not done, building with clang, libc++ and C++11 support
    does not work: libc++ defines the iterator tag classes in an inline
    namespace inside the std namespace, and forward-declaring those
    classes inside the std namespace itself in qiterator.h causes an
    ambiguity that clang solves by choosing the incomplete-declared class
    declared in the enclosing std namespace.
    
    This is probably the "clang build problem" reported in commit
    19e2b4d6eb733d9fd4eb69c0622b699fd08a3203 to qtbase, which cannot be
    directly cherry-picked without breaking other classes due to QT_NO_STL
    still being present in Qt 4.
    
    Change-Id: I26e33915347d3f94ef2e10b68fca6b2099ec9491
    Reviewed-by: Bradley T. Hughes <bradley.hughes@nokia.com>

diff --git a/src/corelib/tools/qiterator.h b/src/corelib/tools/qiterator.h
index 0747940..b9d8da6 100644
--- ./src/corelib/tools/qiterator.h
+++ ./src/corelib/tools/qiterator.h
@@ -46,10 +46,12 @@
 
 QT_BEGIN_HEADER
 
+#ifdef QT_NO_STL
 namespace std {
     struct bidirectional_iterator_tag;
     struct random_access_iterator_tag;
 }
+#endif
 
 QT_BEGIN_NAMESPACE
 
