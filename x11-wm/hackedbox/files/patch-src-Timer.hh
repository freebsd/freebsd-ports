--- src/Timer.hh.old	Sun Aug  1 22:30:04 2004
+++ src/Timer.hh	Sun Aug  1 22:33:02 2004
@@ -98,9 +98,10 @@
   ~_timer_queue(void) {}
 
   void release(const _Tp& value) {
-    c.erase(std::remove(c.begin(), c.end(), value), c.end());
+    _Base::c.erase(std::remove(_Base::c.begin(), _Base::c.end(), value),
+							_Base::c.end());
     // after removing the item we need to make the heap again
-    std::make_heap(c.begin(), c.end(), comp);
+    std::make_heap(_Base::c.begin(), _Base::c.end(), _Base::comp);
   }
   bool empty(void) const { return _Base::empty(); }
   size_t size(void) const { return _Base::size(); }
