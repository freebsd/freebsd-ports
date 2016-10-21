# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-desktop
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for cinnamon

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common \
		xkeyboard-config>=0:x11/xkeyboard-config \
		libxkbfile>=0:x11/libxkbfile
RUN_DEPENDS=	xkeyboard-config>=0:x11/xkeyboard-config \
		libxkbfile>=0:x11/libxkbfile

USE_XORG=	x11 xrandr xext
USES=		autoreconf gettext gmake libtool pathfix pkgconfig \
		shebangfix tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build
SHEBANG_FILES=	files/usr/bin/cinnamon-desktop-migrate-mediakeys
python_OLD_CMD=	/usr/bin/python2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
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
		org.cinnamon.desktop.keybindings.gschema.xml \
		org.cinnamon.desktop.keybindings.media-keys.gschema.xml \
		org.cinnamon.desktop.keybindings.wm.gschema.xml \
		org.cinnamon.desktop.lockdown.gschema.xml \
		org.cinnamon.desktop.media-handling.gschema.xml \
		org.cinnamon.desktop.notifications.gschema.xml \
		org.cinnamon.desktop.privacy.gschema.xml \
		org.cinnamon.desktop.screensaver.gschema.xml \
		org.cinnamon.desktop.session.gschema.xml \
		org.cinnamon.desktop.sound.gschema.xml \
		org.cinnamon.desktop.thumbnail-cache.gschema.xml \
		org.cinnamon.desktop.thumbnailers.gschema.xml \
		org.cinnamon.desktop.wm.preferences.gschema.xml

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}
.for d in bin
	@${MV} ${WRKSRC}/files/usr/${d} ${WRKSRC}/files${PREFIX}
.endfor

	@${REINPLACE_CMD} -e 's|find -min|find . -|g' \
		${WRKSRC}/files/Makefile.am

.include <bsd.port.mk>
