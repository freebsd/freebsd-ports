PORTNAME=	gnome-pie
PORTVERSION=	0.7.3
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Circular application launcher
WWW=		https://schneegans.github.io/gnome-pie.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbamf3.so:sysutils/bamf \
		libgee-0.8.so:devel/libgee \
		libharfbuzz.so:print/harfbuzz \
		libunique-1.0.so:x11-toolkits/unique
RUN_DEPENDS=	gnome-settings-daemon>=2.32.1_4:sysutils/gnome-settings-daemon

USES=		cmake desktop-file-utils gnome libarchive pkgconfig \
		vala:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Simmesimme
GH_PROJECT=	Gnome-Pie
USE_GNOME=	cairo gnomemenus3 gtk30 librsvg2 libwnck3 libxml2
USE_XORG=	x11 xtst

SHEBANG_FILES=	resources/locale/compile-po.sh

REINPLACE_ARGS=	-i ''
PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR}

OPTIONS_DEFINE=		DOCS MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	INSTALL_DOCS
MANPAGES_CMAKE_BOOL=	INSTALL_MANPAGES
NLS_BUILD_DEPENDS=	bash:shells/bash
NLS_USES=		gettext shebangfix
NLS_CMAKE_BOOL=		INSTALL_NLS

post-patch:
	${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},1' \
		-e 's,%%DESKTOPDIR%%,${DESKTOPDIR},1' \
		-e 's,%%PREFIX%%,${PREFIX},1' \
		${WRKSRC}/src/actions/actionRegistry.vala \
		${WRKSRC}/src/gui/indicator.vala \
		${WRKSRC}/src/utilities/paths.vala

post-build-NLS-on:
	(cd ${WRKSRC}/resources/locale && ./compile-po.sh)

.include <bsd.port.mk>
