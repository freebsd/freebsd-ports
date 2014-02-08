# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#    $MCom: ports/trunk/x11/cinnamon/Makefile 18993 2014-01-29 21:33:54Z kwm $

PORTNAME=	cinnamon
PORTVERSION=	2.0.14
PORTREVISION=	1
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
		libcjs.so:${PORTSDIR}/lang/cjs \
		libaccountsservice.so:${PORTSDIR}/sysutils/accountsservice
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		gnome-themes-standard>=3.0.0:${PORTSDIR}/x11-themes/gnome-themes-standard \
		cinnamon-control-center:${PORTSDIR}/sysutils/cinnamon-control-center \
		cinnamon-translations>=0:${PORTSDIR}/misc/cinnamon-translations \
		cinnamon-screensaver:${PORTSDIR}/x11/cinnamon-screensaver \
		nemo:${PORTSDIR}/x11-fm/nemo \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml

WRKSRC=		${WRKDIR}/Cinnamon-${PORTVERSION}

USE_XORG=	x11 xfixes sm
USES=		gettext gmake pathfix pkgconfig shebangfix
# this happens before moving the file to ${PREFIX} (which then will be copied to ${STAGEDIR}${PREFIX}
SHEBANG_FILES=	files/usr/bin/cinnamon2d
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

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
RUN_DEPENDS+=	cinnamon-translations>=0:${PORTSDIR}/misc/cinnamon-translations
.endif

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

	@${REINPLACE_CMD} -e 's|=/usr/bin/|=${PREFIX}/bin/|g' \
		${WRKSRC}/files${PREFIX}/share/xsessions/cinnamon2d.desktop \
		${WRKSRC}/files${PREFIX}/share/xsessions/cinnamon.desktop \
		${WRKSRC}/files${PREFIX}/share/applications/cinnamon2d.desktop

# Some python files use #! /usr/bin/python (note the space between the bang and the python interpreter
	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

post-install:
	@${PYTHON_CMD} ${WRKSRC}/files/generate_desktop_files

	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/cinnamon/libcinnamon.so

.include <bsd.port.mk>
