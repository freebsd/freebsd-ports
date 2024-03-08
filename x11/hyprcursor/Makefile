PORTNAME=	hyprcursor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Hyprland cursor format, library and utilities
WWW=		https://github.com/hyprwm/hyprcursor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzip.so:archivers/libzip \
		libhyprlang.so:devel/hyprlang

USES=		compiler:c++11-lib cmake:testing gnome pathfix pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo librsvg2
GH_ACCOUNT=	hyprwm

.include <bsd.port.mk>
