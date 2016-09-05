# Created by: Stas Timoknin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	blt
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux

MAINTAINER=	devel@stasyan.com
COMMENT=	BLT widget extension to Tcl/Tk scripting language development (Linux Fedora 10)

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	tcl85 tk85 xorglibs

RPMVERSION=	28.z.fc10
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}" TCLVERSION="8.5"

.include <bsd.port.mk>
