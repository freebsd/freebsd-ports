# New ports collection makefile for:	x11-toolkits/linux-f10-blt
# Date created:				2009-08-04
# Whom:					Stas Timoknin <stast@bsdportal.ru>
# $FreeBSD$
#

PORTNAME=	blt
PORTVERSION=	2.4
CATEGORIES=	x11-toolkits linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	stast@bsdportal.ru
COMMENT=	BLT widget extension to Tcl/Tk scripting language development (Linux Fedora 10)

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	tcl84 tk84 xorglibs
LINUX_DIST_VER=	10
RPMVERSION=	28.z.fc10
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}" TCLVERSION="8.5"

.include <bsd.port.mk>
