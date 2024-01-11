PORTNAME=	wmutils-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Set of window manipulation tools
WWW=		https://github.com/wmutils/core

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxcb-cursor.so:x11/xcb-util-cursor

USES=		localbase:ldflags xorg

USE_GITHUB=	yes
GH_ACCOUNT=	wmutils
GH_PROJECT=	core

MAKE_ARGS= 	PREFIX="${PREFIX}" CC="${CC}" MANPREFIX="${PREFIX}/share/man"

USE_XORG=	xcb

CONFLICTS=	wtf  # games/wtf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
