# Created by: anders@hack.org
# $FreeBSD$

PORTNAME=	pekwm
PORTVERSION=	0.1.17
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://pekwm.org/projects/3/files/

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Light, Unobtrusive, and configurable windowmanager

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler gmake iconv:wchar_t jpeg localbase pkgconfig \
		tar:bzip2 xorg
USE_XORG=	xft xpm x11 sm ice xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shape --enable-xinerama --enable-xrandr \
		--enable-xft --enable-image-xpm --enable-image-jpeg \
		--enable-image-png --disable-debug \
		--disable-pedantic
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
LDFLAGS+=	${ICONV_LIB}

.include <bsd.port.mk>
