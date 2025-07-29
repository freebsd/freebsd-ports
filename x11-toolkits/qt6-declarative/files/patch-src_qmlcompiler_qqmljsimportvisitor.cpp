Upstream patch for the qmlcompiler crash
https://code.qt.io/cgit/qt/qtdeclarative.git/commit/?h=6.9&id=672e6777e8e6a8fd86c7877075e7a8aa0ea0a31a

--- src/qmlcompiler/qqmljsimportvisitor.cpp.orig	2025-05-28 20:21:26 UTC
+++ src/qmlcompiler/qqmljsimportvisitor.cpp
@@ -1041,16 +1041,17 @@ void QQmlJSImportVisitor::checkRequiredProperties()
                     : u"here"_s;
 
             if (!prevRequiredScope.isNull()) {
-                auto sourceScope = prevRequiredScope->baseType();
-                suggestion = QQmlJSFixSuggestion{
-                    "%1:%2:%3: Property marked as required in %4."_L1
-                            .arg(sourceScope->filePath())
-                            .arg(sourceScope->sourceLocation().startLine)
-                            .arg(sourceScope->sourceLocation().startColumn)
-                            .arg(requiredScopeName),
-                    sourceScope->sourceLocation()
-                };
-                suggestion->setFilename(sourceScope->filePath());
+                if (auto sourceScope = prevRequiredScope->baseType()) {
+                    suggestion = QQmlJSFixSuggestion{
+                        "%1:%2:%3: Property marked as required in %4."_L1
+                                .arg(sourceScope->filePath())
+                                .arg(sourceScope->sourceLocation().startLine)
+                                .arg(sourceScope->sourceLocation().startColumn)
+                                .arg(requiredScopeName),
+                        sourceScope->sourceLocation()
+                    };
+                    suggestion->setFilename(sourceScope->filePath());
+                }
             } else {
                 message += " (marked as required by %1)"_L1.arg(requiredScopeName);
             }
