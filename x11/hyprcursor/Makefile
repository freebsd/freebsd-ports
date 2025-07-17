PORTNAME=	hyprcursor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.12
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland cursor format, library and utilities
WWW=		https://github.com/hyprwm/hyprcursor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzip.so:archivers/libzip \
		libhyprlang.so:devel/hyprlang \
		libtomlplusplus.so:devel/tomlplusplus
RUN_DEPENDS=	xcur2png:x11/xcur2png

USES=		compiler:c++11-lib cmake:testing gnome pathfix pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo librsvg2
GH_ACCOUNT=	hyprwm
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

post-patch:
# Respect PREFIX for icons
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/lib${PORTNAME}/${PORTNAME}.cpp

.include <bsd.port.mk>
