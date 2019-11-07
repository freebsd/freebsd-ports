# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	bgs
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://s01.de/~gottox/files/bgs/ \
		http://laffaye.free.fr/distfiles/

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Simple X11 BackGround Setter using Imlib2

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		xorg
USE_XORG=	x11 xinerama

PLIST_FILES=	bin/bgs \
		man/man1/bgs.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bgs

.include <bsd.port.mk>
