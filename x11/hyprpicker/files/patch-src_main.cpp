--- src/main.cpp.orig	2026-05-04 23:34:34 UTC
+++ src/main.cpp
@@ -94,12 +94,24 @@ int main(int argc, char** argv, char** envp) {
             }
             case 's': {
                 float value;
+#if defined(_LIBCPP_VERSION) && _LIBCPP_VERSION < 200000
+                try {
+                    size_t pos;
+                    value = std::stof(optarg, &pos);
+                    if (pos != strlen(optarg))
+                        throw std::invalid_argument("");
+                } catch (...) {
+                    std::cerr << "Invalid scale value: " << optarg << "\n";
+                    exit(1);
+                }
+#else
                 auto  result = std::from_chars(optarg, optarg + strlen(optarg), value);
 
                 if (result.ec != std::errc() || result.ptr != optarg + strlen(optarg)) {
                     std::cerr << "Invalid scale value: " << optarg << "\n";
                     exit(1);
                 }
+#endif
 
                 if (value < 1.0f || value > 10.0f) {
                     std::cerr << "Scale must be between 1 and 10!\n";
