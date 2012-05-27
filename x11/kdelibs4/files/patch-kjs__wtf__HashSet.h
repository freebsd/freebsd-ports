commit a8ae408985e3eadee91ce95b584e768a205fec02
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Sun May 27 17:10:27 2012 -0300

    Fix the build with clang 3.1 (and possibly ICC).
    
    Use the `template' keyword to disambiguate the calls here. Similar to
    what was done in WebKit's WTF revision 37062.
    
    Reviewed-by:	SadEagle on IRC

diff --git a/kjs/wtf/HashSet.h b/kjs/wtf/HashSet.h
index a1519d5..88ddf79 100644
--- ./kjs/wtf/HashSet.h
+++ ./kjs/wtf/HashSet.h
@@ -181,7 +181,7 @@ namespace WTF {
     inline HashSet<Value, HashFunctions, Traits>::find(const T& value)
     {
         typedef HashSetTranslatorAdapter<ValueType, ValueTraits, T, Translator> Adapter;
-        return m_impl.find<T, Adapter>(value);
+        return m_impl.template find<T, Adapter>(value);
     }
 
     template<typename Value, typename HashFunctions, typename Traits>
@@ -190,7 +190,7 @@ namespace WTF {
     inline HashSet<Value, HashFunctions, Traits>::find(const T& value) const
     {
         typedef HashSetTranslatorAdapter<ValueType, ValueTraits, T, Translator> Adapter;
-        return m_impl.find<T, Adapter>(value);
+        return m_impl.template find<T, Adapter>(value);
     }
 
     template<typename Value, typename HashFunctions, typename Traits>
@@ -198,7 +198,7 @@ namespace WTF {
     inline bool HashSet<Value, HashFunctions, Traits>::contains(const T& value) const
     {
         typedef HashSetTranslatorAdapter<ValueType, ValueTraits, T, Translator> Adapter;
-        return m_impl.contains<T, Adapter>(value);
+        return m_impl.template contains<T, Adapter>(value);
     }
 
     template<typename T, typename U, typename V>
