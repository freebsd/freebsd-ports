# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	flwm
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Fast Light Window Manager

LICENSE=	GPLv2+

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		autoreconf gmake xorg
GNU_CONFIGURE=	yes
USE_XORG=	x11 xt

USE_GITHUB=	yes
GH_ACCOUNT=	bbidulock

PLIST_FILES=	bin/flwm \
		man/man1/flwm.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/flwm.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
