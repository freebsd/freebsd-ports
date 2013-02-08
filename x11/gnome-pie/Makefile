# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-pie
PORTVERSION=	0.5.2
#PORTREVISION=	0
CATEGORIES=	x11
# Waiting for a tag on the GitHub repository https://github.com/Simmesimme/Gnome-Pie...
MASTER_SITES=	LOCAL/nivit/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Circular application launcher

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
RUN_DEPENDS=	gnome-icons-elementary>=2.5:${PORTSDIR}/x11-themes/gnome-icons-elementary \
		gnome-settings-daemon>=2.32.1_4:${PORTSDIR}/sysutils/gnome-settings-daemon
LIB_DEPENDS=	Xtst:${PORTSDIR}/x11/libXtst \
		cairo:${PORTSDIR}/graphics/cairo \
		gee:${PORTSDIR}/devel/libgee \
		unique:${PORTSDIR}/x11-toolkits/unique

INSTALLS_ICONS=	yes
OPTIONS_DEFINE=	DOCS MANPAGES NLS
OPTIONS_DEFAULT=	DOCS MANPAGES NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS=	-DINSTALL_DOCS:BOOL=ON
.endif

.if ${PORT_OPTIONS:MMANPAGES}
MAN1=	gnome-pie.1
.else
CMAKE_ARGS+=	-DNO_INSTALL_MANPAGES:BOOL=ON
.endif

.if ${PORT_OPTIONS:MNLS}
CMAKE_ARGS+=	-DINSTALL_NLS:BOOL=ON
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
CMAKE_ARGS+=	-DINSTALL_NLS:BOOL=OFF
PLIST_SUB=	NLS="@comment "
.endif

PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

REINPLACE_ARGS=	-e 's,%%DATADIR%%,${DATADIR},1' \
		-e 's,%%DESKTOPDIR%%,${DESKTOPDIR},1' \
		-e 's,%%PREFIX%%,${PREFIX},1' \
		-i.bak

SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GNOME=	gconf2 gnomemenus gtk20 libwnck
USE_PKGCONFIG=	build

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/src/actions/actionRegistry.vala ${WRKSRC}/src/utilities/paths.vala

post-install:
	@${CAT} ${PKGMESSAGE}

gnome-pie-user:
	gconftool-2 --type string --set /desktop/gnome/interface/icon_theme "elementary"
	gconftool-2 --type bool --set /desktop/gnome/interface/menus_have_icons true

.include <bsd.port.mk>
