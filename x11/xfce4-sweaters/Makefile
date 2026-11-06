PORTNAME=	xfce4-sweaters
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.1
CATEGORIES=	x11 xfce

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Cozy knitted borders for your XFCE4 windows

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycairo>=0:graphics/py-pycairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygobject>=0:devel/py-pygobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xlib>=0:x11-toolkits/py-python-xlib@${PY_FLAVOR}

USES=		desktop-file-utils gnome python
USE_GITHUB=	yes
GH_ACCOUNT=	yumiaura
USE_GNOME=	gtk30 introspection
USE_PYTHON=	autoplist pep517

PLIST_FILES=	etc/xdg/autostart/${PORTNAME}.desktop \
		share/applications/${PORTNAME}.desktop

NO_ARCH=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/debian/applications/${PORTNAME}.desktop \
	    ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${WRKSRC}/debian/autostart/${PORTNAME}.desktop \
	    ${STAGEDIR}${PREFIX}/etc/xdg/autostart/

.include <bsd.port.mk>
