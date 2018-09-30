# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-shell-extensions
PORTVERSION=	3.28.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME desktop shell extensions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sassc:textproc/sassc
LIB_DEPENDS=	libgjs.so:lang/gjs
RUN_DEPENDS=	gnome-shell>=3.28.0:x11/gnome-shell

PORTSCOUT=	limitw:1,even

NO_ARCH=	yes
USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 gnomedesktop3 intlhack
USE_LDCONFIG=	yes
MESON_ARGS=	-Dextension_set=all \
		-Dclassic_mode=true

GLIB_SCHEMAS=	org.gnome.shell.extensions.auto-move-windows.gschema.xml \
		org.gnome.shell.extensions.classic-overrides.gschema.xml \
		org.gnome.shell.extensions.example.gschema.xml \
		org.gnome.shell.extensions.native-window-placement.gschema.xml \
		org.gnome.shell.extensions.screenshot-window-sizer.gschema.xml \
		org.gnome.shell.extensions.user-theme.gschema.xml \
		org.gnome.shell.extensions.window-list.gschema.xml

.include <bsd.port.mk>
