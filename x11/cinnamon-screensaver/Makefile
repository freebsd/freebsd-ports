PORTNAME=	cinnamon-screensaver
DISTVERSION=	6.4.0
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cinnamon screen saver and locker
WWW=		https://github.com/linuxmint/cinnamon-screensaver

LICENSE=	GPLv2+ LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libdbus-glib-1.so:devel/dbus-glib \
		libxdo.so:x11/xdotool
RUN_DEPENDS=	${LOCALBASE}/lib/pam_gnome_keyring.so:security/gnome-keyring \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xapp>0:x11/py-python-xapp@${PY_FLAVOR} \
		${LOCALBASE}/libexec/unix-selfauth-helper:security/unix-selfauth-helper

USES=		gnome meson pkgconfig python shebangfix xorg localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_XORG=	x11 xext xrandr

USE_GNOME=	cairo gdkpixbuf glib20 gtk30 introspection:build pygobject3

SHEBANG_GLOB=	*.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_LDCONFIG=	yes

SUB_FILES+=	cinnamon-screensaver.pam

OPTIONS_DEFINE=		LOCKING SETRES XINERAMA
OPTIONS_DEFAULT=	LOCKING XINERAMA

LOCKING_DESC=	Compile in support for locking the display
SETRES_DESC=	Use setresuid/setresgid in the setuid.c helper

LOCKING_MESON_TRUE=	locking
SETRES_MESON_TRUE=	setres
XINERAMA_USE=		XORG=xinerama
XINERAMA_MESON_TRUE=	xinerama

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/src/pamhelper/cinnamon-screensaver-pam-helper.c \
		${WRKSRC}/libcscreensaver/test-passwd.c \
		${WRKSRC}/src/cinnamon-screensaver-command.py \
		${WRKSRC}/src/cinnamon-screensaver-main.py \
		${WRKSRC}/src/passwordEntry.py
	@${REINPLACE_CMD} -e 's|/etc/pam|${PREFIX}/etc/pam|g' \
		${WRKSRC}/libcscreensaver/cs-auth-pam.c

post-install:
	${INSTALL_DATA} ${WRKDIR}/cinnamon-screensaver.pam \
		${STAGEDIR}${PREFIX}/etc/pam.d/cinnamon-screensaver

.include <bsd.port.mk>
