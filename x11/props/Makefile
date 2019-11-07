# Created by: jraynard
# $FreeBSD$

PORTNAME=	props
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://komquats.com/distfiles/ \
		LOCAL/cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The OpenLook props application

CONFLICTS=	xview-clients-3.2.1.4.19*

LIB_DEPENDS=	libxview.so:x11-toolkits/xview

MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/props
USES=		imake xorg
USE_XORG=	x11 xext
MAKE_ARGS=	INFOFILES=""

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/locale/C/props; \
		${INSTALL_DATA} ${WRKSRC}/C/* ${STAGEDIR}${PREFIX}/lib/X11/locale/C/props

.include <bsd.port.mk>
