# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-desktop
PORTVERSION=	3.38.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for GNOME 3

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LIB

PORTSCOUT=	limitw:1,even

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		xkeyboard-config>=0:x11/xkeyboard-config \
		itstool:textproc/itstool
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		cantarell-fonts>=0:x11-fonts/cantarell-fonts \
		xkeyboard-config>=0:x11/xkeyboard-config

USES=		bison gettext gnome localbase:ldflags meson \
		pkgconfig python:3.4+ tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build
USE_XORG=	x11
USE_LDCONFIG=	yes
MESON_ARGS=	-Dgnome_distributor="FreeBSD GNOME Project" \
		-Dudev=disabled \
		-Dsystemd=disabled \
		-Dgtk_doc=false

.include <bsd.port.mk>
