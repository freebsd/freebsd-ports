# ex:ts=8
# Ports collection makefile for:	wmapp
# Date Created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wmapp
PORTVERSION=	0.0.4.2
PORTREVISION=	0
CATEGORIES=	x11-toolkits windowmaker
MASTER_SITES=	http://www.princeton.edu/~kmccarty/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DockApp Graphics Library

PLIST_FILES=	lib/libwmapp.a
USE_XLIB=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${X11BASE}/include
MAKE_ENV=	LFLAGS="-L. -L${X11BASE}/lib -lXpm -lXext -lX11 -lwmapp"
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s|export |#export |g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|malloc\.h|stdlib.h|g" ${WRKSRC}/xwrapper.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libwmapp.a ${PREFIX}/lib

.include <bsd.port.mk>
