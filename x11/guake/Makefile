PORTNAME=	guake
PORTVERSION=	3.4.0
PORTREVISION=	5
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
DISTNAME=	Guake-${PORTVERSION}

MAINTAINER=	daniel@shafer.cc
COMMENT=	Dropdown terminal made for the GNOME desktop
WWW=		http://guake-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notify2>0:devel/py-notify2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		keybinder-gtk3>0:x11/keybinder-gtk3 \
		keybinder>0:x11/keybinder \
		libnotify>0:devel/libnotify

USES=		cpe gmake gnome libtool localbase pathfix python \
		shebangfix
USE_GNOME=	glib20 gtk30 intltool vte3
USE_PYTHON=	distutils noflavors
GLIB_SCHEMAS=	org.guake.gschema.xml
CPE_VENDOR=	guake-project
NO_ARCH=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

MANPAGES_MAKE_ENV_OFF=	man_MANS=""

GETTEXT_FIX=	about.py boxes.py customcommands.py dialogs.py globals.py \
		gsettings.py guake_app.py keybindings.py main.py menus.py \
		notebook.py prefs.py

post-extract:
	@${REINPLACE_CMD} -e 's|PYTHON_INTERPRETER=python3|PYTHON_INTERPRETER=${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile
.for x in ${GETTEXT_FIX}
	@${REINPLACE_CMD} -e '/import/s|locale|gettext|g' ${WRKSRC}/guake/${x}
.endfor

post-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
		install-schemas install-locale

.include <bsd.port.mk>
