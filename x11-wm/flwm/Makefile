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

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_XORG=	x11 xt
GNU_CONFIGURE=	yes

CFLAGS+=	-DFL_LIBRARY

MAN1=		flwm.1
PLIST_FILES=	bin/flwm

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g; /^main/s|^|int |g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|^LIBS =.*|LIBS = `fltk-config --ldflags`|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
