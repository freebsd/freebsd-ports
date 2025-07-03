PORTNAME=	xcur2png
DISTVERSION=	0.7.1
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert X cursors to PNG images
WWW=		https://github.com/eworm-de/xcur2png

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	xcursor
GH_ACCOUNT=	eworm-de
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
