# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-pie
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Circular application launcher

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
RUN_DEPENDS=	gnome-icons-faenza>=1.3:${PORTSDIR}/x11-themes/gnome-icons-faenza \
		gnome-settings-daemon>=2.32.1_4:${PORTSDIR}/sysutils/gnome-settings-daemon
LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libgee.so:${PORTSDIR}/devel/libgee06 \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique

USE_XORG=	xtst
GH_ACCOUNT=	Simmesimme
GH_PROJECT=	Gnome-Pie
GH_COMMIT=	5ea8b11
GH_TAGNAME=	v${PORTVERSION}

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

DOCS_CMAKE_ON=	-DINSTALL_DOCS:BOOL=ON
MANPAGES_CMAKE_OFF=	-DNO_INSTALL_MANPAGES:BOOL=ON

NLS_CMAKE_ON=	-DINSTALL_NLS:BOOL=ON
NLS_USES=		gettext
NLS_CMAKE_OFF=	-DINSTALL_NLS:BOOL=OFF

REINPLACE_ARGS=	-e 's,%%DATADIR%%,${DATADIR},1' \
		-e 's,%%DESKTOPDIR%%,${DESKTOPDIR},1' \
		-e 's,%%PREFIX%%,${PREFIX},1' \
		-e '/has_resize_grip/d' -i ''

SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

USES+=		cmake pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gconf2 gnomemenus gtk20 libwnck

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/src/actions/actionRegistry.vala \
			${WRKSRC}/src/gui/indicator.vala \
			${WRKSRC}/src/utilities/paths.vala \
			${WRKSRC}/resources/ui/*.ui

gnome-pie-user:
	gconftool-2 --type string --set /desktop/gnome/interface/icon_theme "Faenza"
	gconftool-2 --type bool --set /desktop/gnome/interface/menus_have_icons true

.include <bsd.port.mk>
