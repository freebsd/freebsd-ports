PORTNAME=	hyprcursor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.13
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
GH_ACCOUNT=	hyprwm

USE_GNOME=	cairo librsvg2
USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION_MAJOR=0 \
		SOVERSION_FULL=${DISTVERSION:C/-.*//}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
# Respect PREFIX for icons
	@${REINPLACE_CMD} 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/lib${PORTNAME}/${PORTNAME}.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
