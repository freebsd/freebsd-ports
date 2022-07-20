PORTNAME=	gnome-pie
PORTVERSION=	0.5.7
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Circular application launcher

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
RUN_DEPENDS=	gnome-settings-daemon>=2.32.1_4:sysutils/gnome-settings-daemon
LIB_DEPENDS=	libbamf3.so:sysutils/bamf \
		libgee-0.8.so:devel/libgee \
		libunique-1.0.so:x11-toolkits/unique

USES=		cmake gnome pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo gnomemenus3 gtk30 librsvg2 libwnck3
USE_XORG=	xtst

DOCS_CMAKE_ON=	-DINSTALL_DOCS:BOOL=ON

GH_ACCOUNT=	Simmesimme
GH_PROJECT=	Gnome-Pie

MANPAGES_CMAKE_OFF=	-DNO_INSTALL_MANPAGES:BOOL=ON

NLS_CMAKE_BOOL=	INSTALL_NLS
NLS_USES=	gettext

OPTIONS_DEFAULT=	MANPAGES
OPTIONS_DEFINE=	DOCS MANPAGES NLS
OPTIONS_SUB=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR}

REINPLACE_ARGS=	 -i ''

post-patch:
	${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},1' \
		-e 's,%%DESKTOPDIR%%,${DESKTOPDIR},1' \
		-e 's,%%PREFIX%%,${PREFIX},1' \
		-e '/has_resize_grip/d' ${WRKSRC}/src/actions/actionRegistry.vala \
		${WRKSRC}/src/gui/indicator.vala \
		${WRKSRC}/src/utilities/paths.vala \
		${WRKSRC}/resources/ui/*.ui

.include <bsd.port.mk>
