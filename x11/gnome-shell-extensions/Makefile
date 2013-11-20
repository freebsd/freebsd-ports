# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	gnome-shell-extensions
PORTVERSION=	3.6.2
CATEGORIES=	x11 gnome
MASTER_SITES=	LOCAL/kwm

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME desktop shell extensions

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	gnome-shell>=3.6.2:${PORTSDIR}/x11/gnome-shell

NO_STAGE=	yes
USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomedesktop3 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extensions=all

GLIB_SCHEMAS=	org.gnome.shell.extensions.alternate-tab.gschema.xml \
		org.gnome.shell.extensions.alternative-status-menu.gschema.xml \
		org.gnome.shell.extensions.auto-move-windows.gschema.xml \
		org.gnome.shell.extensions.dock.gschema.xml \
		org.gnome.shell.extensions.example.gschema.xml \
		org.gnome.shell.extensions.native-window-placement.gschema.xml \
		org.gnome.shell.extensions.user-theme.gschema.xml

.include <bsd.port.mk>
