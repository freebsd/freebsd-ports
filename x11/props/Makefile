# New ports collection makefile for:	props
# Date created:		3 January 1998
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	props
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The OpenLook props application

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/props
USE_IMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-install:
		${MKDIR} ${X11BASE}/lib/X11/locale/C/props; \
		${INSTALL_DATA} ${WRKSRC}/C/* ${X11BASE}/lib/X11/locale/C/props

.include <bsd.port.post.mk>
