# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon
PORTVERSION=	1.8.8.1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	Fork of GNOME Shell with layout similar to GNOME 2

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libcaribou.so:${PORTSDIR}/accessibility/caribou \
		libmuffin.so:${PORTSDIR}/x11-wm/muffin \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libtelepathy-logger.so:${PORTSDIR}/net-im/telepathy-logger \
		libfolks.so:${PORTSDIR}/net-im/folks \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libcroco-0.6.so:${PORTSDIR}/textproc/libcroco \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter \
		libgjs.so:${PORTSDIR}/lang/gjs \
		libaccountsservice.so:${PORTSDIR}/sysutils/accountsservice
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gnome-themes-standard>=3.0.0:${PORTSDIR}/x11-themes/gnome-themes-standard \
		cinnamon-control-center:${PORTSDIR}/sysutils/cinnamon-control-center \
		nemo:${PORTSDIR}/x11-fm/nemo \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml

WRKSRC=		${WRKDIR}/Cinnamon-1.8.8.1

FETCH_ARGS=	-Fpr
USE_XORG=	x11 xfixes sm
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool autoconf automake
USE_GNOME=	evolutiondataserver3 gconf2 gnomedesktop3 gnomemenus3 \
		gnomeprefix gtk30 intlhack introspection:build
USE_GSTREAMER=	theora vp8 ogg
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes

GLIB_SCHEMAS=	org.cinnamon.gschema.xml

CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}
.for d in bin lib share
	@${MV} ${WRKSRC}/files/usr/${d} ${WRKSRC}/files${PREFIX}
.endfor

	@${REINPLACE_CMD} -e 's|/usr/share/cinnamon|${STAGEDIR}${PREFIX}/share/|g ;\
		s|/usr/lib|${STAGEDIR}${PREFIX}/share/|g' \
			${WRKSRC}/files/generate_desktop_files

	@${REINPLACE_CMD} -e 's|"usr/lib|"${STAGEDIR}${PREFIX}/share/|g ;\
		s|"usr/share|"${STAGEDIR}${PREFIX}/share/|g' \
			${WRKSRC}/files/generate_desktop_files

	@${MV} ${WRKSRC}/files/${PREFIX}/share/cinnamon/locale \
		${WRKSRC}/files/${PREFIX}/share/locale
	@${MV} ${WRKSRC}/files/etc ${WRKSRC}/files${PREFIX}
	@${MV} ${WRKSRC}/files/${PREFIX}/lib/* ${WRKSRC}/files${PREFIX}/share/
	@${RMDIR} ${WRKSRC}/files/${PREFIX}/lib

	@${REINPLACE_CMD} -e 's|/usr/lib|${PREFIX}/lib/|g' \
		${WRKSRC}/files${PREFIX}/share/cinnamon-settings/bin/capi.py

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/share/cinnamon/locale" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share/cinnamon/locale|${PREFIX}/share/locale|g"

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share/|g ;\
		s|/usr/lib|${PREFIX}/share/|g' \
			${WRKSRC}/data/theme/cinnamon.css \
			${WRKSRC}/js/ui/main.js \
			${WRKSRC}/js/ui/panel.js \
			${WRKSRC}/js/ui/expo.js \
			${WRKSRC}/makepot \
			${WRKSRC}/src/st/st-background-effect.c \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-launcher \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/brightness@cinnamon.org/applet.js \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/panel-launchers@cinnamon.org/cinnamon-add-panel-launcher.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/sound@cinnamon.org/applet.js \
			${WRKSRC}/files${PREFIX}/share/cinnamon/desklets/launcher@cinnamon.org/editorDialog.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon/desklets/launcher@cinnamon.org/desklet.js \
			${WRKSRC}/files${PREFIX}/share/cinnamon-screensaver-lock-dialog/cinnamon-screensaver-lock-dialog.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-menu-editor/cme/config.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/cinnamon-settings.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_backgrounds.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_keyboard.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_extensions.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_calendar.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_desklets.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_themes.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/modules/cs_applets.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/data/spices/applet-detail.html \
			${WRKSRC}/files${PREFIX}/share/cinnamon-settings/bin/capi.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-screensaver-lock-dialog/cinnamon-screensaver-lock-dialog.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-menu-editor/cme/config.py \
			${WRKSRC}/files${PREFIX}/share/cinnamon-menu-editor/cme/MainWindow.py \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-menu-editor \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-settings \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-looking-glass \
			${WRKSRC}/files${PREFIX}/bin/cinnamon-screensaver-lock-dialog

	@${REINPLACE_CMD} -e 's|const NetworkManager = imports.gi.NetworkManager;||g ;\
		s|const NMClient = imports.gi.NMClient;||g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/network\@cinnamon.org/applet.js

	@${REINPLACE_CMD} -e 's|const GnomeBluetoothApplet = imports.gi.GnomeBluetoothApplet;||g ;\
		s|const GnomeBluetooth = imports.gi.GnomeBluetooth;||g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/bluetooth\@cinnamon.org/applet.js

	@${REINPLACE_CMD} -e 's|/usr/lib/gnome-session|${PREFIX}/libexec|g' \
		${WRKSRC}/files${PREFIX}/share/gnome-session/sessions/cinnamon.session

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	@${REINPLACE_CMD} -e '/prefix/s|/usr|${PREFIX}|g ; \
		/datadir/s|/usr|${PREFIX}|g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon-menu-editor/cme/config.py

	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' \
		${WRKSRC}/files${PREFIX}/share/xsessions/cinnamon.desktop \
		${WRKSRC}/files${PREFIX}/share/xsessions/cinnamon2d.desktop

	@${REINPLACE_CMD} -e 's|AM_GNU_GETTEXT_VERSION(\[0.17\])||g ;\
		s|AM_GNU_GETTEXT(\[external\])||g' \
		${WRKSRC}/configure.ac

# Some python files use #! /usr/bin/python (note the space between the bang and the python interpreter
	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

post-install:
	@${PYTHON_CMD} ${WRKSRC}/files/generate_desktop_files

.include <bsd.port.mk>
