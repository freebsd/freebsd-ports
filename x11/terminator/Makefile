# New ports collection makefile for:	terminator
# Date created:		2008-03-14
# Whom:			Thomas Hurst <tom@hur.st>
#
# $FreeBSD$
#

PORTNAME=	terminator
PORTVERSION=	0.96
PORTREVISION=	3
CATEGORIES=	x11 python
MASTER_SITES=	http://launchpadlibrarian.net/80778747/ \
		http://hur.st/mirror/terminator/

MAINTAINER=	tom@hur.st
COMMENT=	Multiple GNOME terminals in one window

LICENSE=	GPLv2

OPTIONS_DEFINE=	NLS GCONF
GCONF_DESC=	Use GNOME Terminal settings
OPTIONS_DEFAULT=	NLS GCONF

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Terminator

INSTALLS_ICONS=	yes

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

PYSETUP+=	--without-icon-cache
.if empty(PORT_OPTIONS:MNLS)
PLIST_SUB+=	NLS="@comment "
PYSETUP+=	--without-gettext
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte
.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	pygnome2
.endif
USE_GNOME+=	pygtk2

MAN1=	terminator.1
MAN5=	terminator_config.5

.include <bsd.port.post.mk>
