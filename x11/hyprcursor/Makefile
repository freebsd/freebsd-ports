PORTNAME=	hyprcursor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.10
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f8e8455e998e.patch:-p1 # https://github.com/hyprwm/hyprcursor/pull/66
PATCHFILES+=	2b522b0350ea.patch:-p1 # https://github.com/hyprwm/hyprcursor/pull/71

MAINTAINER=	jbeich@FreeBSD.org
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
