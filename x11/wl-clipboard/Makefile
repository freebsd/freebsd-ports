# $FreeBSD$

PORTNAME=	wl-clipboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-40
DISTVERSIONSUFFIX=	-g46f21d2
CATEGORIES=	x11 wayland

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Command-line copy/paste utilities for Wayland

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	bugaevc

PLIST_FILES=	bin/wl-copy \
		bin/wl-paste \
		man/man1/wl-clipboard.1.gz \
		man/man1/wl-copy.1.gz \
		man/man1/wl-paste.1.gz

.include <bsd.port.mk>
