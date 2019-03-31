# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	terminator
PORTVERSION=	1.0
CATEGORIES=	x11 python
MASTER_SITES=	http://launchpad.net/terminator/trunk/1.0/+download/

MAINTAINER=	tom@hur.st
COMMENT=	Multiple GNOME terminals in one window

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0:devel/py-notify@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/keybinder/_keybinder.so:x11/keybinder \
		${PYTHON_PKGNAMEPREFIX}vte>=0:x11-toolkits/py-vte@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		gnome python:2.7 shebangfix
USE_GNOME=	pygtk2 intltool
USE_PYTHON=	distutils

PYDISTUTILS_PKGNAME=	Terminator

INSTALLS_ICONS=	yes

SHEBANG_FILES=	terminator.wrapper

OPTIONS_DEFINE=		NLS GCONF
OPTIONS_DEFAULT=	GCONF
OPTIONS_SUB=		yes
GCONF_DESC=		Use GNOME Terminal settings
GCONF_USE=		GNOME=pygnome2
NLS_USES=		gettext

.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MNLS}
PYDISTUTILS_SETUP+=	--without-gettext
post-patch:
	${CP} ${WRKSRC}/data/terminator.desktop.in ${WRKSRC}/data/terminator.desktop
	${REINPLACE_CMD} -e 's/^_//' ${WRKSRC}/data/terminator.desktop
	${CP} ${WRKSRC}/data/terminator.appdata.xml.in ${WRKSRC}/data/terminator.appdata.xml
	${REINPLACE_CMD} \
		-e 's|<_|<|' \
		-e 's|</_|</|' \
		${WRKSRC}/data/terminator.appdata.xml
.endif

PYDISTUTILS_SETUP+=	--without-icon-cache

.include <bsd.port.post.mk>
