# Created by: Thomas Hurst <tom@hur.st>

PORTNAME=	terminator
PORTVERSION=	2.1.1
PORTREVISION=	0
CATEGORIES=	x11 python
MASTER_SITES=	https://github.com/gnome-terminator/terminator/archive/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Multiple GNOME terminals in one window

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/lib/libkeybinder-3.0.so:x11/keybinder-gtk3 \
		${LOCALBASE}/lib/libnotify.so:devel/libnotify \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		gnome python:3.5+ shebangfix gettext
USE_GNOME=	intltool pygobject3 vte3
USE_PYTHON=	autoplist distutils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PYDISTUTILS_PKGNAME=	Terminator

INSTALLS_ICONS=	yes

NO_ARCH=	yes

.include <bsd.port.pre.mk>

PYDISTUTILS_SETUP+=	--without-icon-cache

.include <bsd.port.post.mk>
