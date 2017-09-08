# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	alttab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	x11

MAINTAINER=	dg@syrec.org
COMMENT=	Task switcher for minimalistic window managers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
USE_XORG=	x11 xft
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	sagb

PLIST_FILES=	bin/alttab \
		man/man1/alttab.1.gz

PORTDOCS=	README xmonad.md

.include <bsd.port.mk>
