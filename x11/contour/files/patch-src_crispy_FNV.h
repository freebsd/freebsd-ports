--- src/crispy/FNV.h.orig	2026-01-06 17:41:07 UTC
+++ src/crispy/FNV.h
@@ -41,16 +41,47 @@ class fnv
         return (*this)((*this)(memory, value), moreValues...);
     }
 
-    template <typename... V>
-    constexpr U operator()(U memory, std::basic_string_view<T> str, V... moreValues) const noexcept
+    /// Incrementally hashes a trivially copyable value.
+    ///
+    /// The value is treated as a sequence of bytes and hashed byte-wise.
+    /// This overload explicitly excludes std::string and std::string_view,
+    /// which are handled by dedicated overloads.
+    template <typename V,
+              typename = std::enable_if_t<
+                  std::is_trivially_copyable_v<V> &&
+                  !std::is_same_v<V, std::string> &&
+                  !std::is_same_v<V, std::string_view>>>
+    constexpr U operator()(U memory, V const& value) const noexcept
     {
+        auto const* bytes =
+            reinterpret_cast<unsigned char const*>(&value);
+        for (std::size_t i = 0; i < sizeof(V); ++i)
+            memory = (*this)(memory, bytes[i]);
+        return memory;
+    }
+
+    /// Incrementally hashes a string view and additional values (char only).
+    ///
+    /// Each character in @p str is hashed sequentially before applying
+    /// the remaining values in @p moreValues.
+    template <typename Dummy = T, typename... V,
+              typename = std::enable_if_t<std::is_same_v<Dummy, char>>>
+    constexpr U operator()(U memory,
+                           std::string_view str,
+                           V... moreValues) const noexcept
+    {
         for (auto const ch: str)
             memory = (*this)(memory, ch);
         return (*this)(memory, moreValues...);
     }
 
     /// Builds the FNV hash between [_begin, _end)
-    constexpr U operator()(U memory, std::basic_string_view<T> str) const noexcept
+    /// Builds the FNV hash for a string view (char only).
+    ///
+    /// Hashes all characters in @p str starting from the given memory value.
+    template <typename Dummy = T,
+              typename = std::enable_if_t<std::is_same_v<Dummy, char>>>
+    constexpr U operator()(U memory, std::string_view str) const noexcept
     {
         for (auto const ch: str)
             memory = (*this)(memory, ch);
@@ -70,7 +101,12 @@ class fnv
     constexpr U operator()(T const* data, size_t len) const noexcept { return (*this)(data, data + len); }
 
     /// Builds the FNV hash between [_begin, _begin + len)
-    constexpr U operator()(std::basic_string<T> const& str) const noexcept
+    /// Builds the FNV hash for a std::string (char only).
+    ///
+    /// Hashes the string's character data sequentially.
+    template <typename Dummy = T,
+              typename = std::enable_if_t<std::is_same_v<Dummy, char>>>
+    constexpr U operator()(std::string const& str) const noexcept
     {
         return (*this)(str.data(), str.data() + str.size());
     }
