PORTNAME=	flwm
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Fast Light Window Manager
WWW=		https://github.com/bbidulock/flwm

LICENSE=	GPLv2+

DEPRECATED=	Last upstream release and activity was in 2015
EXPIRATION_DATE=	2024-01-19

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		autoreconf gmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	bbidulock
USE_XORG=	x11 xt

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/flwm \
		man/man1/flwm.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/flwm.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
