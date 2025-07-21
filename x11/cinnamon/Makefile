PORTNAME=	cinnamon
DISTVERSION=	6.4.10
PORTREVISION=	3
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fork of GNOME Shell with layout similar to GNOME 2
WWW=		https://github.com/linuxmint/cinnamon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/EGL/eglmesaext.h:graphics/mesa-dri \
		${PYTHON_PKGNAMEPREFIX}libsass>0:www/py-libsass@${PY_FLAVOR}
LIB_DEPENDS=	libcjs.so:lang/cjs \
		libmuffin.so:x11-wm/muffin \
		libcinnamon-menu-3.so:x11/cinnamon-menus \
		libdbus-1.so:devel/dbus \
		libpolkit-agent-1.so:sysutils/polkit \
		libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libxapp.so:x11/xapp \
		libgcr-base-3.so:security/gcr3 \
		libcinnamon-desktop.so:x11/cinnamon-desktop
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		gnome-themes-extra>3.0.0:x11-themes/gnome-themes-extra \
		caribou>0:accessibility/caribou \
		cinnamon-control-center:sysutils/cinnamon-control-center \
		cinnamon-screensaver:x11/cinnamon-screensaver \
		cinnamon-settings-daemon>0:sysutils/cinnamon-settings-daemon \
		nemo:x11-fm/nemo \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xapp>0:x11/py-python-xapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-pam>0:security/py-python-pam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss>0:textproc/py-tinycss@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		gkbd-keyboard-display:x11/libgnomekbd \
		gucharmap:deskutils/gucharmap \
		keybinder-gtk3>0:x11/keybinder-gtk3 \
		timezonemap>0:misc/timezonemap \
		${LOCALBASE}/lib/girepository-1.0/GSound-1.0.typelib:audio/gsound \
		gnome-backgrounds>0:x11-themes/gnome-backgrounds \
		metacity:x11-wm/metacity \
		tint2:x11/tint \
		lspci:sysutils/pciutils \
		${LOCALBASE}/libexec/polkit-gnome-authentication-agent-1:sysutils/polkit-gnome \
		${LOCALBASE}/libexec/cups-pk-helper-mechanism:print/cups-pk-helper \
		${PYTHON_PKGNAMEPREFIX}tinycss2>0:textproc/py-tinycss2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		xdg-open:devel/xdg-utils \
		xdg-user-dirs-gtk>0:x11/xdg-user-dirs-gtk \
		inxi:sysutils/inxi \
		wget:ftp/wget

USES=		compiler:c11 cpe gettext-runtime gettext-tools:run gl gnome \
		meson perl5 pkgconfig python shebangfix xorg
CPE_VENDOR=	linuxmint
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 intltool introspection libxml2 pygobject3
USE_XORG=	x11 xfixes
USE_GL=		gl
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	files/* src/data-to-c.pl data/theme/parse-sass.sh

USE_LDCONFIG=	yes
# These libs are found via rpath mechanism
NO_SHLIB_REQUIRES_GLOB=	libmuffin-clutter-* libmuffin-cogl-*

BINARY_ALIAS=	python3=${PYTHON_CMD}
MESON_ARGS=	-Ddisable_networkmanager=true

GLIB_SCHEMAS=	org.cinnamon.gschema.xml

OPTIONS_DEFINE=	DOCS NLS WAYLAND RECORDER
OPTIONS_DEFAULT=	RECORDER
OPTIONS_SUB=	yes

RECORDER_DESC=	Build the cinnamon recorder into source

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs
WAYLAND_MESON_TRUE=	wayland
RECORDER_MESON_TRUE=	build_recorder
RECORDER_USES=	gstreamer
RECORDER_USE=	GSTREAMER=vpx

NLS_RUN_DEPENDS=	cinnamon-translations>0:misc/cinnamon-translations

post-patch:
	@${REINPLACE_CMD} -e '/prefix/s|/usr|${PREFIX}|g ;\
		/datadir/s|/usr|${PREFIX}|g ;\
		/libdir/s|/usr|${PREFIX}|g ;\
		/libexecdir/s|/usr|${PREFIX}|g' \
			${WRKSRC}/files/usr/share/cinnamon/cinnamon-menu-editor/cme/config.py

	@${FIND} ${WRKSRC} -name \* -type f | ${XARGS} ${EGREP} -l "/usr/share/cinnamon/locale" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share/cinnamon/locale|${PREFIX}/share/locale|g"

	@${FIND} ${WRKSRC} -name \* -type f | ${XARGS} ${EGREP} -l "/usr/share" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/share|${PREFIX}/share|g"

	@${FIND} ${WRKSRC} -name \* -type f | ${XARGS} ${EGREP} -l "/usr/lib" | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/lib|${PREFIX}/lib|g"

	@${FIND} ${WRKSRC} -name \* -type f | ${XARGS} ${EGREP} -l "/usr/bin" | \
		${XARGS} ${REINPLACE_CMD} -e '\x/usr/bin/passwdx!s|/usr/bin|${PREFIX}/bin|g'

	@${REINPLACE_CMD} -e "/prefixes = /s|'/usr'|'${PREFIX}'|" \
		${WRKSRC}/files/usr/bin/xlet-about-dialog

	# Stop loading network-manager applet by default
	@${REINPLACE_CMD} -e "s|, 'panel1:right:7:network@cinnamon.org'||" \
		${WRKSRC}/data/org.cinnamon.gschema.xml

	# Fix build with no network-manager
	@${REINPLACE_CMD} -e '/cs-bluetooth/d; /cs-network/d' \
		${WRKSRC}/files/usr/share/cinnamon/cinnamon-settings/cinnamon-settings.py

	@${REINPLACE_CMD} -e 's/nm-applet;//' \
		${WRKSRC}/meson.build

	@${REINPLACE_CMD} -e '/imports.ui.networkAgent/d' \
		${WRKSRC}/js/ui/main.js
	# End of Fix build with no network-manager

	# Fix symlink installation
	@${REINPLACE_CMD} -e "s|DESTDIR|MESON_INSTALL_DESTDIR_PREFIX|" \
		${WRKSRC}/install-scripts/add_symlink.py

	# Some python files use #! /usr/bin/python (note the space between the bang and the python interpreter
	@${FIND} ${WRKSRC} -name \* -type f | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

	# Fix applets that try to exec just python3
	@${REINPLACE_CMD} -e "/'python3[' ]/s|python3|${PYTHON_CMD}|" \
		${WRKSRC}/files/usr/share/cinnamon/applets/printers@cinnamon.org/applet.js \
		${WRKSRC}/files/usr/share/cinnamon/applets/grouped-window-list@cinnamon.org/menus.js

	# Fix system lp(1) overlapping with cups' lp(1)
	@${REINPLACE_CMD} -e "/'lp'/s|lp|${PREFIX}/bin/lp|" \
		${WRKSRC}/files/usr/share/cinnamon/applets/printers@cinnamon.org/applet.js

	# gtk-doc builds erroneous documentation files otherwise
	@${FIND} ${WRKSRC} -name '*.orig' -type f -delete
	@${FIND} ${WRKSRC} -name '*.bak' -type f -delete

	# Adhere to our hier(7)
	@${MKDIR} ${WRKSRC}/files${PREFIX}
	@${MV} ${WRKSRC}/files/etc ${WRKSRC}/files${PREFIX}
.	for i in bin share
		@${MV} ${WRKSRC}/files/usr/${i} ${WRKSRC}/files${PREFIX}
.	endfor

.include <bsd.port.mk>
