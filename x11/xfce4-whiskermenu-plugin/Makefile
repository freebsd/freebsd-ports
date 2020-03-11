# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-whiskermenu-plugin
PORTVERSION=	2.4.3
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Alternate menu for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang gettext-tools gnome localbase pkgconfig \
		tar:bzip2 xfce:gtk3
USE_GNOME=	cairo gtk30
USE_XFCE=	panel

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} '/add_subdirectory(po)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
