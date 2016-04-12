# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	terminator
PORTVERSION=	0.97
PORTREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	http://launchpad.net/terminator/trunk/0.97/+download/

MAINTAINER=	tom@hur.st
COMMENT=	Multiple GNOME terminals in one window

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0:devel/py-notify \
		${PYTHON_SITELIBDIR}/keybinder/_keybinder.so:x11/keybinder \
		${PYTHON_PKGNAMEPREFIX}vte>=0:x11-toolkits/py-vte

USES=		python
USE_GNOME=	pygtk2 intltool
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	Terminator

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		NLS GCONF
OPTIONS_DEFAULT=	NLS GCONF
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
.endif

PYDISTUTILS_SETUP+=	--without-icon-cache

pre-patch:
	${REINPLACE_CMD} -e 's/libc\.so/libc.so.7/' ${WRKSRC}/terminatorlib/freebsd.py

.include <bsd.port.post.mk>
