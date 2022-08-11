PORTNAME=	cinnamon-screensaver
PORTVERSION=	4.8.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cinnamon screen saver and locker

LICENSE=	GPLv2+ LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/lib/pam_gnome_keyring.so:security/gnome-keyring \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xapp>0:x11/py-python-xapp@${PY_FLAVOR}

USES=		gettext-tools gnome meson pkgconfig python:3.5+ shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_XORG=	x11 xext xinerama xrandr xscrnsaver

USE_GNOME=	cairo gdkpixbuf2 intltool introspection:build libgnomekbd pygobject3

SHEBANG_GLOB=	*.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_LDCONFIG=	yes

SUB_FILES+=	cinnamon-screensaver.pam

post-patch:
	@${FIND} ${WRKSRC} -name \*.py | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/bin|${PREFIX}/bin|g' \
		-e 's|/usr/lib|${PREFIX}/lib|g' \
		-e 's|/usr/share|${PREFIX}/share|g'
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/src/pamhelper/cinnamon-screensaver-pam-helper.c \
		${WRKSRC}/libcscreensaver/test-passwd.c

post-install:
	${INSTALL_DATA} ${WRKDIR}/cinnamon-screensaver.pam \
		${STAGEDIR}${PREFIX}/etc/pam.d/cinnamon-screensaver

.include <bsd.port.mk>
