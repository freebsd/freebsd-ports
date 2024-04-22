PORTNAME=	xkbcomp
DISTVERSION=	1.4.7
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Compile XKB keyboard description

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix tar:xz xorg xorg-cat:app
USE_XORG=	x11 xkbfile

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/xkbcomp \
		libdata/pkgconfig/xkbcomp.pc \
		share/man/man1/xkbcomp.1.gz

.include <bsd.port.mk>
