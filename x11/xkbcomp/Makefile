PORTNAME=	xkbcomp
PORTVERSION=	1.4.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Compile XKB keyboard description

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix xorg xorg-cat:app
USE_XORG=	x11 xkbfile

PLIST_FILES=	bin/xkbcomp \
		libdata/pkgconfig/xkbcomp.pc \
		man/man1/xkbcomp.1.gz

.include <bsd.port.mk>
