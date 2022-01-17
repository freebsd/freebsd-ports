# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>

PORTNAME=	cinnamon
PORTVERSION=	4.8.6
PORTREVISION=	1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	aa0bf5b13078.patch:-p1 # https://github.com/linuxmint/cinnamon/pull/10606

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fork of GNOME Shell with layout similar to GNOME 2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ca_root_nss>0:security/ca_root_nss
LIB_DEPENDS=	libcjs.so:lang/cjs \
		libmuffin.so:x11-wm/muffin \
		libcinnamon-menu-3.so:x11/cinnamon-menus \
		libdbus-1.so:devel/dbus \
		libpolkit-agent-1.so:sysutils/polkit \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libstartup-notification-1.so:x11/startup-notification \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		ca_root_nss>0:security/ca_root_nss \
		gnome-themes-extra>3.0.0:x11-themes/gnome-themes-extra \
		caribou>0:accessibility/caribou \
		cinnamon-control-center:sysutils/cinnamon-control-center \
		cinnamon-screensaver:x11/cinnamon-screensaver \
		nemo:x11-fm/nemo \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xapp>0:x11/py-python-xapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-pam>0:security/py-python-pam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss>0:textproc/py-tinycss@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		timezonemap>0:misc/timezonemap \
		gnome-backgrounds>0:x11-themes/gnome-backgrounds \
		metacity:x11-wm/metacity \
		tint2:x11/tint

USES=		compiler:c11 cpe gettext gl gnome meson pkgconfig python:3.5+ shebangfix xorg
CPE_VENDOR=	linuxmint
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool introspection libxml2 pygobject3
USE_XORG=	x11 xfixes
USE_GL=		gl
USE_GSTREAMER1=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	files/*

USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}
MESON_ARGS=	-Ddisable_networkmanager=true

GLIB_SCHEMAS=	org.cinnamon.gschema.xml

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_DEFAULT=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

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
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/bin|${PREFIX}/bin|g"

	@${REINPLACE_CMD} -e '/cs-bluetooth/d; /cs-network/d' \
		${WRKSRC}/files/usr/share/cinnamon/cinnamon-settings/cinnamon-settings.py

	# Some python files use #! /usr/bin/python (note the space between the bang and the python interpreter
	@${FIND} ${WRKSRC} -name \* -type f | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -e "s|#!.*python.*|#!/usr/bin/env python|g"

	# gtk-doc builds erroneous documentation files otherwise
	@${FIND} ${WRKSRC} -name '*.orig' -type f -delete
	@${FIND} ${WRKSRC} -name '*.bak' -type f -delete

	# Adhere to our hier(7)
	@${MKDIR} ${WRKSRC}/files${PREFIX}
	@${MV} ${WRKSRC}/files/etc ${WRKSRC}/files${PREFIX}
.	for i in bin share
		@${MV} ${WRKSRC}/files/usr/${i} ${WRKSRC}/files${PREFIX}
.	endfor

post-install:
	# Ship the GNOME Backgrounds set
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/cinnamon-background-properties
	@${LN} -s ${PREFIX}/share/gnome-background-properties/adwaita.xml \
		${STAGEDIR}${PREFIX}/share/cinnamon-background-properties/adwaita.xml
	@${LN} -s ${PREFIX}/share/gnome-background-properties/gnome-backgrounds.xml \
		${STAGEDIR}${PREFIX}/share/cinnamon-background-properties/gnome-backgrounds.xml

.include <bsd.port.mk>
