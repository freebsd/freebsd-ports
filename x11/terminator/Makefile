# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	terminator
PORTVERSION=	0.96
PORTREVISION=	4
CATEGORIES=	x11 python
MASTER_SITES=	http://launchpadlibrarian.net/80778747/ \
		http://hur.st/mirror/terminator/

MAINTAINER=	tom@hur.st
COMMENT=	Multiple GNOME terminals in one window

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/keybinder/_keybinder.so:${PORTSDIR}/x11/keybinder \
		${PYTHON_PKGNAMEPREFIX}vte>=0:${PORTSDIR}/x11-toolkits/py-vte

OPTIONS_DEFINE=	NLS GCONF
GCONF_DESC=	Use GNOME Terminal settings
OPTIONS_DEFAULT=	NLS GCONF

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Terminator

INSTALLS_ICONS=	yes

WANT_GNOME=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
PYSETUP+=	--without-gettext
.endif

.include <bsd.port.pre.mk>

PYDISTUTILS_SETUP+=	--without-icon-cache

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	pygnome2
.endif
USE_GNOME+=	pygtk2

MAN1=	terminator.1
MAN5=	terminator_config.5

.include <bsd.port.post.mk>
