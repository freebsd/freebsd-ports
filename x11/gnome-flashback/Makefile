PORTNAME=	gnome-flashback
PORTVERSION=	3.58.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Flashback session and helper applications
WWW=		https://gitlab.gnome.org/GNOME/gnome-flashback

LICENSE=	GPLv3

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		xkeyboard-config>0:x11/xkeyboard-config
LIB_DEPENDS=	libgnome-panel.so:x11/gnome-panel \
		libpolkit-gobject-1.so:sysutils/polkit \
		libibus-1.0.so:textproc/ibus \
		libconsolekit.so:sysutils/consolekit2 \
		libxkbfile.so:x11/libxkbfile \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libpulse.so:audio/pulseaudio \
		libupower-glib.so:sysutils/upower \
		libgdm.so:x11/gdm \
		libasound.so:audio/alsa-lib \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	xkeyboard-config>0:x11/xkeyboard-config \
		gnome-session>0:x11/gnome-session \
		metacity:x11-wm/metacity \
		gnome-applets>0:x11/gnome-applets \
		tecla:x11/tecla \
		alacarte:x11/alacarte \
		nautilus:x11-fm/nautilus \
		gnome-terminal:x11/gnome-terminal \
		xdg-user-dirs-gtk-update:x11/xdg-user-dirs-gtk \
		cantarell-fonts>0:x11-fonts/cantarell-fonts \
		source-code-pro-ttf>0:x11-fonts/source-code-pro-ttf

# x11/gnome-shell is mandatory for x11/gdm and it provides the screenshot
# service through the org.gnome.Shell.Screenshot interface
RUN_DEPENDS+=	gnome-shell>0:x11/gnome-shell

USES=		gettext gmake gnome libtool pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 gnomedesktop3 pango
USE_XORG=	x11 xcb xext xfixes xi xrandr xxf86vm

CONFIGURE_ARGS=	--without-compiz-session
INSTALL_TARGET=	install-strip

SUB_FILES=	gnome-flashback pkg-message
SUB_LIST=	EXAMPLESDIR=${EXAMPLESDIR:S|${PORTNAME}|gnome-shell|}

GLIB_SCHEMAS=	00_gnome-flashback.gschema.override \
		org.gnome.gnome-flashback.desktop.background.gschema.xml \
		org.gnome.gnome-flashback.desktop.enums.xml \
		org.gnome.gnome-flashback.desktop.gschema.xml \
		org.gnome.gnome-flashback.desktop.icons.gschema.xml \
		org.gnome.gnome-flashback.gschema.xml \
		org.gnome.gnome-flashback.keybindings.gschema.xml \
		org.gnome.gnome-flashback.notifications.gschema.xml \
		org.gnome.gnome-flashback.system-indicators.input-sources.gschema.xml

post-extract:
# Add support for ConsoleKit
	@${CP} ${FILESDIR}/gf-consolekit-* \
		${WRKSRC}/dbus/
	@${CP} ${FILESDIR}/org.freedesktop.ConsoleKit* \
		${WRKSRC}/dbus/
# Re-add XDG autostart .desktop files removed for systemd service
	@${CP} ${FILESDIR}/*.desktop.in.in \
		${WRKSRC}/data/autostart/

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${LOCALBASE}|" \
		${WRKSRC}/gnome-flashback/libscreensaver/gf-screensaver.c
	@${REINPLACE_CMD} -e 's|X-GNOME-HiddenUnderSystemd|#X-GNOME-HiddenUnderSystemd|' \
		${WRKSRC}/data/applications/gnome-flashback.desktop.in

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pam.d
	${INSTALL_DATA} ${WRKDIR}/gnome-flashback \
		${STAGEDIR}${PREFIX}/etc/pam.d

.include <bsd.port.mk>
