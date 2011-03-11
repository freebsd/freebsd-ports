# New ports collection makefile for:	props
# Date created:		3 January 1998
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	props
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The OpenLook props application

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/props
USE_IMAKE=	yes
USE_XORG=	x11 xext
MAKE_ARGS=	INFOFILES=""

post-install:
		${MKDIR} ${PREFIX}/lib/X11/locale/C/props; \
		${INSTALL_DATA} ${WRKSRC}/C/* ${PREFIX}/lib/X11/locale/C/props

.include <bsd.port.mk>
