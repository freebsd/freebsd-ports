# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	bgs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple X11 BackGround Setter using Imlib2

LICENSE=	MIT

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		pkgconfig xorg
USE_XORG=	x11 xinerama

USE_GITHUB=	yes
GH_ACCOUNT=	Gottox

PLIST_FILES=	bin/bgs \
		man/man1/bgs.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bgs

.include <bsd.port.mk>
