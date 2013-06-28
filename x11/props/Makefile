# Created by: jraynard
# $FreeBSD$

PORTNAME=	props
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://komquats.com/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The OpenLook props application

CONFLICTS=	xview-clients-3.2.1.4.19*

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/props
USES=		imake
USE_XORG=	x11 xext
MAKE_ARGS=	INFOFILES=""

post-install:
		${MKDIR} ${PREFIX}/lib/X11/locale/C/props; \
		${INSTALL_DATA} ${WRKSRC}/C/* ${PREFIX}/lib/X11/locale/C/props

.include <bsd.port.mk>
