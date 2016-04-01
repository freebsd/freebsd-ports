# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-pie
PORTVERSION=	0.5.7
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Circular application launcher

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala
RUN_DEPENDS=	gnome-settings-daemon>=2.32.1_4:sysutils/gnome-settings-daemon
LIB_DEPENDS=	libbamf3.so:sysutils/bamf \
		libgee-0.8.so:devel/libgee \
		libunique-1.0.so:x11-toolkits/unique

DOCS_CMAKE_ON=	-DINSTALL_DOCS:BOOL=ON

GH_ACCOUNT=	Simmesimme
GH_PROJECT=	Gnome-Pie

INSTALLS_ICONS=	yes

MANPAGES_CMAKE_OFF=	-DNO_INSTALL_MANPAGES:BOOL=ON

NLS_CMAKE_OFF=	-DINSTALL_NLS:BOOL=OFF
NLS_CMAKE_ON=	-DINSTALL_NLS:BOOL=ON
NLS_USES=	gettext

OPTIONS_DEFAULT=	MANPAGES
OPTIONS_DEFINE=	DOCS MANPAGES NLS
OPTIONS_SUB=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR}

REINPLACE_ARGS=	-e 's,%%DATADIR%%,${DATADIR},1' \
		-e 's,%%DESKTOPDIR%%,${DESKTOPDIR},1' \
		-e 's,%%PREFIX%%,${PREFIX},1' -i.bak \
		-e '/has_resize_grip/d' -i ''

USES=		cmake pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gconf2 gnomemenus3 gtk30 librsvg2 libwnck3
USE_XORG=	xtst

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/src/actions/actionRegistry.vala \
		${WRKSRC}/src/gui/indicator.vala \
		${WRKSRC}/src/utilities/paths.vala \
		${WRKSRC}/resources/ui/*.ui

.include <bsd.port.mk>
