PORTNAME=	bgs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple X11 BackGround Setter using Imlib2
WWW=		https://github.com/Gottox/bgs

LICENSE=	MIT

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		pkgconfig xorg
USE_XORG=	x11 xinerama

USE_GITHUB=	yes
GH_ACCOUNT=	Gottox

MAKE_ARGS=	PREFIX="${PREFIX}"

PLIST_FILES=	bin/bgs \
		share/man/man1/bgs.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bgs

.include <bsd.port.mk>
