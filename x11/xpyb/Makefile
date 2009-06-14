# New ports collection makefile for:	xpyb
# Date created:		2008-08-27
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xpyb
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	http://xcb.freedesktop.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	dist
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wahjava@gmail.com
COMMENT=	Python bindings to access X Window System protocol via libxcb

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-proto.pc:${PORTSDIR}/x11/xcb-proto
LIB_DEPENDS=	xcb.2:${PORTSDIR}/x11/libxcb

USE_BZIP2=	yes
USE_PYTHON=	2.5+
USE_GNOME=	gnomehack
PORTDOCS=	README

GNU_CONFIGURE=yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-I${LOCALBASE}/lib"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
