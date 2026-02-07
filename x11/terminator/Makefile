PORTNAME=	terminator
DISTVERSION=	2.1.5
PORTREVISION=	0
CATEGORIES=	x11 python
MASTER_SITES=	https://github.com/gnome-${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Multiple GNOME terminals in one window
WWW=		https://github.com/gnome-terminator/terminator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/lib/libkeybinder-3.0.so:x11/keybinder-gtk3 \
		${LOCALBASE}/lib/libnotify.so:devel/libnotify \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		gnome python shebangfix gettext
USE_GNOME=	intltool pygobject3 vte3
USE_PYTHON=	autoplist noflavors pep517

PYDISTUTILS_PKGNAME=	Terminator

NO_ARCH=	yes

.include <bsd.port.mk>
