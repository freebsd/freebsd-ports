PORTNAME=	xfce4-sweaters
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
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
GH_ACCOUNT=	DtxdF
USE_GNOME=	gtk30 introspection
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
		${INSTALL_DATA} ${WRKSRC}/xdg/icon.svg \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg
.for s in 16 22 24 32 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/hicolor/${s}x${s}/apps/xfce4-sweaters.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor
	${INSTALL_DATA} ${WRKSRC}/xdg/application.desktop \
	    ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${WRKSRC}/xdg/autostart.desktop \
	    ${STAGEDIR}${PREFIX}/etc/xdg/autostart/${PORTNAME}.desktop

.include <bsd.port.mk>
