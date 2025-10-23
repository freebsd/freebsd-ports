PORTNAME=	stalonetray
DISTVERSION=	1.0.1
CATEGORIES=	x11

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	STAnd-aLONE system tray
WWW=		https://d3adb5.github.io/stalonetray/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		libxslt>0:textproc/libxslt

USES=		compiler:c++23-lang meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	d3adb5
USE_XORG=	ice sm x11 xinerama xpm

MESON_ARGS=	-Dnative_kde=disabled \
		-Dxinerama=enabled \
		-Dxpm=enabled
ETCDIR=		${PREFIX}/etc

.include <bsd.port.mk>
