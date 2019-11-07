# $FreeBSD$

PORTNAME=	aphelia
DISTVERSION=	g20181126
CATEGORIES=	x11-wm

MAINTAINER=	hyun@caffeinated.codes
COMMENT=	Light, single-file, minimalist window manager for X11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dmenu_run:x11/dmenu \
		st:x11/sterm

USE_GITHUB=	yes
GH_ACCOUNT=	vardy
GH_TAGNAME=	54c2d6fb18f3121ebaf836fad53ca48a2f3aa812
USES=		xorg
USE_XORG=	x11

PLIST_FILES=	bin/aphelia

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include ${WRKSRC}/aphelia.c \
		${LDFLAGS} -L${LOCALBASE}/lib -lX11 -o ${WRKSRC}/aphelia

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aphelia ${STAGEDIR}${PREFIX}/bin/aphelia

.include <bsd.port.mk>
