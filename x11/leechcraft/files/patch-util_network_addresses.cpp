--- util/network/addresses.cpp.orig	2014-07-28 20:35:44.000000000 +0200
+++ util/network/addresses.cpp	2016-01-26 12:58:09.726934000 +0100
@@ -38,7 +38,7 @@ namespace Util
 	AddrList_t GetLocalAddresses (int defaultPort)
 	{
 		AddrList_t defaultAddrs;
-		const auto locals
+		const auto locals =
 		{
 			QHostAddress::parseSubnet ("10.0.0.0/8"),
 			QHostAddress::parseSubnet ("172.16.0.0/12"),
