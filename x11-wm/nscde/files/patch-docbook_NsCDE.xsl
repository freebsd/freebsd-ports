--- docbook/NsCDE.xsl.orig	2021-05-07 20:46:05 UTC
+++ docbook/NsCDE.xsl
@@ -1,6 +1,6 @@
 <?xml version='1.0'?>
 <xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
-<xsl:import href="/usr/share/xml/docbook/stylesheet/docbook-xsl/html/chunk.xsl"/>
+<xsl:import href="${PREFIX}/share/xsl/docbook/html/chunk.xsl"/>
 <xsl:param name="chunk.section.depth" select="2"></xsl:param>
 <xsl:param name="use.id.as.filename" select="1"></xsl:param>
 <xsl:param name="section.autolabel" select="1"></xsl:param>
