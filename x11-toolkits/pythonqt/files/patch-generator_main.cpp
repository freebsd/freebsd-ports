-- Predefine platform and compiler macros for the PythonQt wrapper generator.
-- The generator uses a bundled copy of simplecpp instead of the system compiler
-- to preprocess Qt headers.  On FreeBSD with libc++ this fails because the
-- bundled preprocessor does not define the usual Clang/FreeBSD macros that
-- libc++ and system headers require.  Predefine the missing macros so the
-- generator can successfully parse Qt 6 headers and produce wrappers.
--
-- Upstream builds the generator and runs it on platforms where the system
-- compiler predefines these values implicitly; FreeBSD needs them explicitly.

--- generator/main.cpp.orig	2026-09-15 16:14:25 UTC
+++ generator/main.cpp
@@ -230,6 +230,37 @@ bool preprocess(const QString& sourceFile, const QStri
 #ifdef Q_PROCESSOR_X86_64
   dui.defines.push_back("__x86_64__");
 #endif
+  dui.defines.push_back("__BYTE_ORDER__=1234");
+  dui.defines.push_back("__ORDER_LITTLE_ENDIAN__=1234");
+  dui.defines.push_back("__ORDER_BIG_ENDIAN__=4321");
+  dui.defines.push_back("__FLOAT_WORD_ORDER__=1234");
+  dui.defines.push_back("__has_feature(x)=0");
+  dui.defines.push_back("__has_extension(x)=0");
+  dui.defines.push_back("__has_attribute(x)=0");
+  dui.defines.push_back("__has_builtin(x)=0");
+  dui.defines.push_back("__has_declspec_attribute(x)=0");
+  dui.defines.push_back("__has_cpp_attribute(x)=0");
+  dui.defines.push_back("__is_identifier(x)=1");
+  dui.defines.push_back("__STDC_HOSTED__=1");
+  dui.defines.push_back("__ELF__=1");
+  dui.defines.push_back("__clang__=1");
+  dui.defines.push_back("__FreeBSD__=15");
+  dui.defines.push_back("_LIBCPP_COMPILER_CLANG_BASED=1");
+  dui.defines.push_back("_LIBCPP_HAS_THREADS=1");
+  dui.defines.push_back("_LIBCPP_HAS_THREAD_API_PTHREAD=1");
+  dui.defines.push_back("__has_include_next(x)=0");
+  dui.defines.push_back("__LP64__=1");
+  dui.defines.push_back("__SIZEOF_LONG__=8");
+  dui.defines.push_back("__SIZEOF_POINTER__=8");
+  dui.defines.push_back("__SIZEOF_SIZE_T__=8");
+  dui.defines.push_back("__SIZEOF_PTRDIFF_T__=8");
+  dui.defines.push_back("__SIZEOF_INT__=4");
+  dui.defines.push_back("__SIZEOF_LONG_LONG__=8");
+  dui.defines.push_back("__SIZEOF_SHORT__=2");
+  dui.defines.push_back("__SIZEOF_FLOAT__=4");
+  dui.defines.push_back("__SIZEOF_DOUBLE__=8");
+  dui.defines.push_back("__SIZEOF_WCHAR_T__=4");
+  dui.defines.push_back("__CHAR_BIT__=8");
   dui.std = "c++20";
   dui.removeComments = true;
 
