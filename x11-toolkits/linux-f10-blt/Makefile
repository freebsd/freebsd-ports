# Created by: Stas Timoknin <stast@bsdportal.ru>
# $FreeBSD: head/x11-toolkits/linux-f10-blt/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	blt
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux

MAINTAINER=	devel@stasyan.com
COMMENT=	BLT widget extension to Tcl/Tk scripting language development (Linux Fedora 10)

USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	tcl85 tk85 xorglibs

RPMVERSION=	28.z.fc10
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}" TCLVERSION="8.5"

NO_STAGE=	yes
.include <bsd.port.mk>
