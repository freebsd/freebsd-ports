# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktray
PORTVERSION=	1.3.9
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	System tray icon support

USES+=		tk
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-exec-prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}
TKPKG=		${PORTNAME}${PORTVERSION}

PLIST_FILES=	lib/${TKPKG}/libtktray.so.1 \
		lib/${TKPKG}/pkgIndex.tcl \
		man/mann/${PORTNAME}.n.gz
PLIST_DIRS=	lib/${TKPKG}

.include <bsd.port.mk>
