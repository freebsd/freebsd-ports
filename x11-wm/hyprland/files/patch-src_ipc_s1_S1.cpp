--- src/ipc/s1/S1.cpp.orig	2026-11-04 06:16:54 UTC
+++ src/ipc/s1/S1.cpp
@@ -145,7 +145,7 @@ SResponse CSocket1::dispatchBatch(std::string request,
             if (i < request.size() && (request[i + 1] == '\\' || request[i + 1] == ';'))
                 ++i;
             else
-                LOG(Log::ERR, "Malformed socket1 request: invalid escape sequence {} at position {}, using it verbatim", request.subview(i, 2), i);
+                LOG(Log::ERR, "Malformed socket1 request: invalid escape sequence {} at position {}, using it verbatim", std::string_view(request).substr(i, 2), i);
         }
         parsedCommand << request[i];
     }
