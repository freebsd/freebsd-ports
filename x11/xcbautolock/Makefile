# $FreeBSD$

PORTNAME=	xcbautolock
PORTVERSION=	0.2
CATEGORIES=	x11

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	XCB base autolocker

LICENSE=	BSD2CLAUSE

USES=		pkgconfig
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	bapt

LIB_DEPENDS=	libxcb-screensaver.so:x11/libxcb

PLIST_FILES=	bin/xcbautolock \
		man/man1/xcbautolock.1.gz

.include <bsd.port.mk>
