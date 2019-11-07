# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon
PORTVERSION=	2.4.6
PORTREVISION=	13
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fork of GNOME Shell with layout similar to GNOME 2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libcaribou.so:accessibility/caribou \
		libgnome-keyring.so:security/libgnome-keyring \
		libmuffin.so:x11-wm/muffin \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libfolks.so:net-im/folks \
		libpulse.so:audio/pulseaudio \
		libcroco-0.6.so:textproc/libcroco \
		libsoup-2.4.so:devel/libsoup \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libcogl.so:graphics/cogl \
		libpolkit-agent-1.so:sysutils/polkit \
		libclutter-glx-1.0.so:graphics/clutter \
		libmozjs-24.so:lang/spidermonkey24 \
		libcjs.so:lang/cjs \
		libjson-glib-1.0.so:devel/json-glib \
		libcinnamon-menu-3.so:x11/cinnamon-menus \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libaccountsservice.so:sysutils/accountsservice
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		ca_root_nss>=0:security/ca_root_nss \
		gnome-themes-extra>=3.0.0:x11-themes/gnome-themes-extra \
		cinnamon-control-center:sysutils/cinnamon-control-center \
		cinnamon-translations>=0:misc/cinnamon-translations \
		cinnamon-screensaver:x11/cinnamon-screensaver \
		nemo:x11-fm/nemo \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

USES=		autoreconf compiler:c11 gettext gmake gnome gl libtool \
		localbase:ldflags pathfix pkgconfig python:2.7 shebangfix xorg
USE_GITHUB=	yes
USE_GL=		gl egl
USE_GNOME=	cairo evolutiondataserver3 gconf2 gnomedesktop3 \
		gnomeprefix gtk30 intlhack introspection
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11 xfixes sm xrandr xext xdamage xcomposite xi

GH_ACCOUNT=	linuxmint

# this happens before moving the file to ${PREFIX} (which then will be copied to ${STAGEDIR}${PREFIX})
SHEBANG_FILES=	files/*	*.py

INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt

INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.cinnamon.gschema.xml

OPTIONS_DEFINE=	NLS

NLS_RUN_DEPENDS=	cinnamon-translations>=0:misc/cinnamon-translations

post-patch:
# we need this for intltoolize otherwise it can't copy the m4 file ...
	@${MKDIR} ${WRKSRC}/m4
	@${MKDIR} ${WRKSRC}/files${PREFIX}
.for d in bin lib share
	@${MV} ${WRKSRC}/files/usr/${d} ${WRKSRC}/files${PREFIX}
.endfor

	@${REINPLACE_CMD} -e 's|--warn-error||g' ${WRKSRC}/src/Makefile.am

	@${REINPLACE_CMD} -e 's|/usr/share/cinnamon|${STAGEDIR}${PREFIX}/share/|g ;\
		s|/usr/lib|${STAGEDIR}${PREFIX}/share/|g' \
			${WRKSRC}/files/generate_desktop_files

	@${REINPLACE_CMD} -e 's|"usr/lib|"${STAGEDIR}${PREFIX}/share/|g ;\
		s|"usr/share|"${STAGEDIR}${PREFIX}/share/|g' \
			${WRKSRC}/files/generate_desktop_files

	@${MV} ${WRKSRC}/files/etc ${WRKSRC}/files${PREFIX}
	@${RM} ${WRKSRC}/files/${PREFIX}/lib/cinnamon-settings/modules/cs_user.py
	# Remove a broken link (is applications-merge used anywhere?)
	@${RM} ${WRKSRC}/files/${PREFIX}/etc/xdg/menus/cinnamon-applications-merged

	@${REINPLACE_CMD} -e 's|AM_GNU_GETTEXT_VERSION(\[0.17\])||g ;\
		s|AM_GNU_GETTEXT(\[external\])||g' \
		${WRKSRC}/configure.ac

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	# is this really needed?
	@${REINPLACE_CMD} -e 's|const NetworkManager = imports.gi.NetworkManager;||g ;\
		s|const NMClient = imports.gi.NMClient;||g' \
			${WRKSRC}/files${PREFIX}/share/cinnamon/applets/network\@cinnamon.org/applet.js

	@${REINPLACE_CMD} -e 's|nm-applet;||g' \
		${WRKSRC}/files${PREFIX}/share/cinnamon-session/sessions/cinnamon.session \
		${WRKSRC}/files${PREFIX}/share/cinnamon-session/sessions/cinnamon2d.session

	@${REINPLACE_CMD} -e '/prefix/s|/usr|${PREFIX}|g ; \
		/datadir/s|/usr|${PREFIX}|g' \
			${WRKSRC}/files${PREFIX}/lib/cinnamon-menu-editor/cme/config.py

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/share/cinnamon/locale" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share/cinnamon/locale|${PREFIX}/share/locale|g"

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/share" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share|${PREFIX}/share|g"

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "/usr/lib" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/lib|${PREFIX}/lib|g"

# The cs_user.py is not patched until we have the python-pam module
	@${REINPLACE_CMD} -e 's|"/usr/bin|"${PREFIX}/bin|g' \
		${WRKSRC}/files${PREFIX}/share/cinnamon/applets/menu@cinnamon.org/applet.js \
		${WRKSRC}/files${PREFIX}/share/cinnamon/applets/user@cinnamon.org/applet.js \
		${WRKSRC}/files${PREFIX}/lib/cinnamon-settings/bin/Spices.py \
#		${WRKSRC}/files${PREFIX}/lib/cinnamon-settings/modules/cs_user.py \
		${WRKSRC}/files${PREFIX}/lib/cinnamon-settings/modules/cs_screensaver.py \
		${WRKSRC}/files${PREFIX}/bin/cinnamon-settings \
		${WRKSRC}/files${PREFIX}/bin/cinnamon-launcher

	@${REINPLACE_CMD} -e '/cs-tablet/d; /cs-bluetooth/d; /cs-network/d' \
			${WRKSRC}/files${PREFIX}/lib/cinnamon-settings/cinnamon-settings.py

	@${REINPLACE_CMD} -e '/increase-opacity/d; /decrease-opacity/d' \
			${WRKSRC}/files${PREFIX}/lib/cinnamon-settings/modules/cs_keyboard.py

	#@${REINPLACE_CMD} -e 's/SIZE\/$$$$CONTEXT/CONTEXT\/$$$$SIZE/g' \
	#		${WRKSRC}/data/icons/Makefile.am

	@${REINPLACE_CMD} -e 's|=/usr/bin/|=${PREFIX}/bin/|g' \
		${WRKSRC}/files${PREFIX}/share/xsessions/cinnamon2d.desktop \
		${WRKSRC}/files${PREFIX}/share/xsessions/cinnamon.desktop \
		${WRKSRC}/files${PREFIX}/share/applications/cinnamon2d.desktop

post-install:
	@${PYTHON_CMD} ${WRKSRC}/files/generate_desktop_files

.include <bsd.port.mk>
