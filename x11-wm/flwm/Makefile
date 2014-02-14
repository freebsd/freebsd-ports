# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	flwm
PORTVERSION=	1.02
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The Fast Light Window Manager

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk-devel

USE_XORG=	x11 xt
GNU_CONFIGURE=	yes

CFLAGS+=	-DFL_LIBRARY

PLIST_FILES=	bin/flwm \
		man/man1/flwm.1.gz

post-patch:
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g; /^main/s|^|int |g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|^LIBS =.*|LIBS = `fltk-config --ldflags`|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/flwm.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
