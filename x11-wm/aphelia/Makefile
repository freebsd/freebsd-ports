PORTNAME=	aphelia
DISTVERSION=	g20190913
CATEGORIES=	x11-wm

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Light, single-file, minimalist window manager for X11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dmenu_run:x11/dmenu \
		st:x11/sterm

USES=		xorg

USE_GITHUB=	yes
GH_ACCOUNT=	vardy
GH_TAGNAME=	8b06c4c
USE_XORG=	x11

PLIST_FILES=	bin/aphelia \
		man/man1/aphelia.1.gz

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include ${WRKSRC}/aphelia.c \
		${LDFLAGS} -L${LOCALBASE}/lib -lX11 -o ${WRKSRC}/aphelia

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aphelia ${STAGEDIR}${PREFIX}/bin/aphelia
	${INSTALL_MAN} ${WRKSRC}/aphelia.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
