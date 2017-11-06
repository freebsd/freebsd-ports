# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	simplestroke
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Detect mouse gestures

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	t6

USES=		pkgconfig
USE_XORG=	x11 xtst

PLIST_FILES=	bin/simplestroke \
		bin/simplestroke-daemon \
		man/man1/simplestroke.1.gz \
		man/man1/simplestroke-daemon.1.gz

.include <bsd.port.mk>
