# New ports collection makefile for:	terminator
# Date created:		2008-03-14
# Whom:			Thomas Hurst <tom@hur.st>
#
# $FreeBSD$
#

PORTNAME=	terminator
PORTVERSION=	0.93
CATEGORIES=	x11 python
MASTER_SITES=	http://launchpadlibrarian.net/44348818/ \
		http://hur.st/mirror/terminator/

MAINTAINER=	tom@hur.st
COMMENT=	Multiple GNOME terminals in one window

OPTIONS=	NLS	"Native language support" 	on \
		GCONF	"Use GNOME Terminal settings"	on

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Terminator

INSTALLS_ICONS=	yes

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

PYSETUP+=	--without-icon-cache
.ifdef(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
PYSETUP+=	--without-gettext
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte
.if defined(WITH_GCONF)
USE_GNOME+=	pygnome2
.endif
USE_GNOME+=	pygtk2

MAN1=	terminator.1
MAN5=	terminator_config.5

.include <bsd.port.post.mk>
