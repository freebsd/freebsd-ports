# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	xbanish
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	t@tobik.me
COMMENT=	Banish the mouse cursor when typing

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	jcs

USE_XORG=	x11 xfixes xi xt

MAKE_ARGS=	X11BASE="${PREFIX}"

PLIST_FILES=	bin/xbanish \
		man/man1/xbanish.1.gz

.include <bsd.port.mk>
