--- ./nepomuk/query/querybuilderdata_p.h
+++ ./nepomuk/query/querybuilderdata_p.h
@@ -32,6 +32,28 @@
 #include "query_p.h"
 #include "groupterm_p.h"
 
+namespace {
+/// A hack to avoid passing extended chars to the bif:search_excerpts method which cannot handle
+/// utf8 chars which use more than one char, ie. wide chars.
+/// Thus, we simply truncate each term at the first wide char.
+QStringList stripExtendedCharsHack(const QStringList& terms) {
+    QStringList newTerms;
+    foreach(const QString& term, terms) {
+        int i = 0;
+        while(i < term.length()) {
+            if(term[i].unicode() > 0x7f) {
+                break;
+            }
+            ++i;
+        }
+        if(i > 0) {
+            newTerms.append(term.left(i));
+        }
+    }
+    return newTerms;
+}
+}
+
 namespace Nepomuk {
     namespace Query {
         class QueryBuilderData
@@ -246,16 +268,23 @@ namespace Nepomuk {
                     for( QHash<QString, QStringList>::const_iterator it = m_fullTextSearchTerms.constBegin();
                          it != m_fullTextSearchTerms.constEnd(); ++it ) {
                         const QString& varName = it.key();
-                        const QStringList& terms = it.value();
-                        // bif:search_excerpt wants a vector of all search terms
-                        excerptParts
-                                << QString::fromLatin1("bif:search_excerpt(bif:vector(bif:charset_recode('%1', '_WIDE_', 'UTF-8')), %2)")
-                            .arg( terms.join(QLatin1String("','")),
-                                  varName );
+                        const QStringList terms = stripExtendedCharsHack(it.value());
+                        if(terms.count()) {
+                            // bif:search_excerpt wants a vector of all search terms
+                            excerptParts
+                                    << QString::fromLatin1("bif:search_excerpt(bif:vector('%1'), %2)")
+                                       .arg( terms.join(QLatin1String("','")),
+                                             varName );
+                        }
                     }
 
-                    return QString::fromLatin1("(bif:concat(%1)) as ?_n_f_t_m_ex_")
-                        .arg(excerptParts.join(QLatin1String(",")));
+                    if(excerptParts.count()) {
+                        return QString::fromLatin1("(bif:concat(%1)) as ?_n_f_t_m_ex_")
+                                .arg(excerptParts.join(QLatin1String(",")));
+                    }
+                    else {
+                        return QString();
+                    }
                 }
                 else {
                     return QString();
