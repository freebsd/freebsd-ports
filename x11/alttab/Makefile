# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	alttab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	x11

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Task switcher for minimalistic window managers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash
LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	sagb
GNU_CONFIGURE=	yes
USE_XORG=	x11 xft xrandr xrender

PLIST_FILES=	bin/alttab \
		man/man1/alttab.1.gz

PORTDOCS=	README \
		alttab.ad \
		wm-setup.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
