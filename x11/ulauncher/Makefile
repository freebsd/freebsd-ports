PORTNAME=	ulauncher
PORTVERSION=	5.15.6
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	https://github.com/Ulauncher/Ulauncher/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Advanced graphical application launcher
WWW=		https://ulauncher.io/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.18:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>=0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Levenshtein>=0:devel/py-Levenshtein@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0:www/py-websocket-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR} \
		${LOCALBASE}/share/gir-1.0/Keybinder-3.0.gir:x11/keybinder-gtk3 \
		${LOCALBASE}/share/gir-1.0/Notify-0.7.gir:devel/libnotify \
		${LOCALBASE}/share/gir-1.0/WebKit2-4.0.gir:www/webkit2-gtk@40 \
		wmctrl:x11/wmctrl-fork

USES=		gettext-tools gnome python
USE_GNOME=	gtk30 intltool pygobject3
USE_PYTHON=	autoplist distutils noflavors
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	APPINDICATOR
OPTIONS_DEFAULT=	APPINDICATOR

APPINDICATOR_DESC=	AppIndicator support
APPINDICATOR_RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/AppIndicator3-0.1.gir:devel/libappindicator

.include <bsd.port.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}
