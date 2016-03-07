# $FreeBSD$

PORTNAME=	xcbautolock
PORTVERSION=	0.1
CATEGORIES=	x11

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	XCB base autolocker

LICENSE=	BSD2CLAUSE

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	bapt

LIB_DEPENDS=	libxcb-screensaver.so:${PORTSDIR}/x11/libxcb

PLIST_FILES=	bin/xcbautolock \
		man/man1/xcbautolock.1.gz

.include <bsd.port.mk>
