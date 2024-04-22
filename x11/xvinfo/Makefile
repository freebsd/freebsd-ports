PORTNAME=	xvinfo
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Print out X-Video extension adaptor information

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_SUFX=	.tar.xz
USES=		xorg xorg-cat:app
USE_XORG=	xv x11

PLIST_FILES=	bin/xvinfo share/man/man1/xvinfo.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
