# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon
PORTVERSION=	2.4.6
PORTREVISION=	7
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fork of GNOME Shell with layout similar to GNOME 2

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libcaribou.so:accessibility/caribou \
		libmuffin.so:x11-wm/muffin \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libtelepathy-logger.so:net-im/telepathy-logger \
		libfolks.so:net-im/folks \
		libpulse.so:audio/pulseaudio \
		libcroco-0.6.so:textproc/libcroco \
		libdbus-glib-1.so:devel/dbus-glib \
		libclutter-glx-1.0.so:graphics/clutter \
		libcjs.so:lang/cjs \
		libcinnamon-menu-3.so:x11/cinnamon-menus \
		libaccountsservice.so:sysutils/accountsservice
RUN_DEPENDS=	py*-dbus>=0:devel/py-dbus \
		ca_root_nss>=0:security/ca_root_nss \
		gnome-themes-standard>=3.0.0:x11-themes/gnome-themes-standard \
		cinnamon-control-center:sysutils/cinnamon-control-center \
		cinnamon-translations>=0:misc/cinnamon-translations \
		cinnamon-screensaver:x11/cinnamon-screensaver \
		nemo:x11-fm/nemo \
		py*-pillow>=0:graphics/py-pillow \
		py*-lxml>=0:devel/py-lxml

USES=		autoreconf compiler:c11 gettext gmake libtool \
		pathfix pkgconfig python shebangfix
USE_GNOME=	evolutiondataserver3 gconf2 gnomedesktop3 \
		gnomeprefix gtk30 intlhack introspection:build

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_PROJECT=	Cinnamon

# this happens before moving the file to ${PREFIX} (which then will be copied to ${STAGEDIR}${PREFIX})
SHEBANG_FILES=	files/usr/bin/cinnamon2d
USE_XORG=	x11 xfixes sm
USE_GSTREAMER=	theora vp8 ogg
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
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

# Some python files use #! /usr/bin/python (note the space between the bang and the python interpreter
	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	@${PYTHON_CMD} ${WRKSRC}/files/generate_desktop_files

.include <bsd.port.mk>
