# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/cinnamon-desktop/Makefile 19786 2014-07-31 10:24:00Z gusi $

PORTNAME=	cinnamon-desktop
PORTVERSION=	2.2.3
CATEGORIES=	x11 gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for cinnamon

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		xkeyboard-config>=0:${PORTSDIR}/x11/xkeyboard-config \
		libxkbfile>=0:${PORTSDIR}/x11/libxkbfile
RUN_DEPENDS=	xkeyboard-config>=0:${PORTSDIR}/x11/xkeyboard-config \
		libxkbfile>=0:${PORTSDIR}/x11/libxkbfile

USE_XORG=	x11 xrandr xext
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
PATHFIX_MAKEFILEIN=	Makefile.am
CONFIGURE_ARGS=	--with-gnome-distributor="FreeBSD GNOME Project"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.cinnamon.desktop.a11y.applications.gschema.xml \
		org.cinnamon.desktop.a11y.keyboard.gschema.xml \
		org.cinnamon.desktop.a11y.magnifier.gschema.xml \
		org.cinnamon.desktop.a11y.mouse.gschema.xml \
		org.cinnamon.desktop.background.gschema.xml \
		org.cinnamon.desktop.default-applications.gschema.xml \
		org.cinnamon.desktop.enums.xml \
		org.cinnamon.desktop.input-sources.gschema.xml \
		org.cinnamon.desktop.interface.gschema.xml \
		org.cinnamon.desktop.lockdown.gschema.xml \
		org.cinnamon.desktop.media-handling.gschema.xml \
		org.cinnamon.desktop.screensaver.gschema.xml \
		org.cinnamon.desktop.session.gschema.xml \
		org.cinnamon.desktop.sound.gschema.xml \
		org.cinnamon.desktop.thumbnail-cache.gschema.xml \
		org.cinnamon.desktop.thumbnailers.gschema.xml \
		org.cinnamon.desktop.wm.preferences.gschema.xml

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
