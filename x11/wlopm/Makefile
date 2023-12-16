PORTNAME=	wlopm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/archive/
DISTNAME=	${DISTVERSIONFULL}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	tino.engel@mail.de
COMMENT=	Wayland output power management
WWW=		https://git.sr.ht/~leon_plickat/wlopm

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-scanner:graphics/wayland
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		gmake localbase:ldflags

ALL_TARGET=	wlopm
CFLAGS+=	-Wno-strict-prototypes
LIBS=		-lwayland-client
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSIONFULL}

PLIST_FILES=	bin/wlopm \
		share/man/man1/wlopm.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wlopm ${STAGEDIR}${PREFIX}/bin/wlopm
	${INSTALL_MAN} ${WRKSRC}/wlopm.1 ${STAGEDIR}${PREFIX}/share/man/man1/wlopm.1

.include <bsd.port.mk>
