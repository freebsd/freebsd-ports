# Created by: anders@hack.org
# $FreeBSD$

PORTNAME=	pekwm
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.1.17
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	x11-wm

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Light, Unobtrusive, and configurable windowmanager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf compiler gmake iconv:wchar_t jpeg \
		localbase pkgconfig tar:bzip2 xorg
USE_XORG=	xft xpm x11 sm ice xext xinerama xrandr
USE_GITHUB=	yes
GH_ACCOUNT=	pekdon
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shape --enable-xinerama --enable-xrandr \
		--enable-xft --enable-image-xpm --enable-image-jpeg \
		--enable-image-png --disable-debug \
		--disable-pedantic
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
LDFLAGS+=	${ICONV_LIB}

.include <bsd.port.mk>
