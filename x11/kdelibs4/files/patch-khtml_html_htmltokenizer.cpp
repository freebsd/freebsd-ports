--- khtml/html/htmltokenizer.cpp.orig	2005-01-14 18:34:45.783473376 -0800
+++ khtml/html/htmltokenizer.cpp	2005-01-14 18:13:22.200607632 -0800
@@ -1693,3 +1693,7 @@
     onHold = _onHold;
 }
 
+bool HTMLTokenizer::isRunningScriptFromTokenizer() const
+{
+    return isExecutingScript();
+}
--- khtml/html/htmltokenizer.h.orig	2005-01-14 18:36:55.359774784 -0800
+++ khtml/html/htmltokenizer.h	2005-01-14 18:12:54.872762096 -0800
@@ -171,6 +171,7 @@
 
     virtual bool isWaitingForScripts() const;
     virtual bool isExecutingScript() const;
+    virtual bool isRunningScriptFromTokenizer() const;
 protected:
     // Internal buffers
     ///////////////////
--- khtml/xml/dom_docimpl.cpp.orig	2005-01-14 18:37:53.073001040 -0800
+++ khtml/xml/dom_docimpl.cpp	2005-01-14 18:18:34.716098056 -0800
@@ -1181,7 +1181,7 @@
     // on an explicit document.close(), the tokenizer might still be waiting on scripts,
     // and in that case we don't want to destroy it because that will prevent the
     // scripts from getting processed.
-    if (m_tokenizer && !m_tokenizer->isWaitingForScripts()) {
+    if (m_tokenizer && !m_tokenizer->isWaitingForScripts() && !m_tokenizer->isRunningScriptFromTokenizer()) {
         delete m_tokenizer;
         m_tokenizer = 0;
     }
--- khtml/xml/xml_tokenizer.h.orig	2005-01-14 18:38:27.401782272 -0800
+++ khtml/xml/xml_tokenizer.h	2005-01-14 18:10:57.609588808 -0800
@@ -122,6 +122,7 @@
     virtual void finish() = 0;
     virtual void setOnHold(bool /*_onHold*/) {}
     virtual bool isWaitingForScripts() const = 0;
+    virtual bool isRunningScriptFromTokenizer() const { return false; }
 
 signals:
     void finishedParsing();
