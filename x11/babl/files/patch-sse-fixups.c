--- extensions/sse-fixups.c~
+++ extensions/sse-fixups.c
@@ -23,6 +23,8 @@
 
 #if defined(__GNUC__) && (__GNUC__ >= 4) && defined(USE_SSE) && defined(USE_MMX)
 
+#include <xmmintrin.h>
+
 #include <stdint.h>
 #include <stdlib.h>
 
@@ -40,11 +42,11 @@ typedef int   g2int   __attribute__ ((ve
 #define g4float_zero      g4float_all(0.0)
 #define g4float_ff        g4float_all(255.0)
 
-#define g4float_max(a,b)    __builtin_ia32_maxps(a, b)
-#define g4float_min(a,b)    __builtin_ia32_minps(a, b)
-#define g4float_cvt2pi(a)   __builtin_ia32_cvtps2pi(a)
-#define g4float_movhl(a,b)  __builtin_ia32_movhlps(a, b)
-#define g4float_emms        __builtin_ia32_emms
+#define g4float_max(a,b)    _mm_max_ps(a, b)
+#define g4float_min(a,b)    _mm_min_ps(a, b)
+#define g4float_cvt2pi(a)   _mm_cvtps_pi32(a)
+#define g4float_movhl(a,b)  _mm_movehl_ps(a, b)
+#define g4float_emms        _mm_empty
 
 
 static INLINE long
