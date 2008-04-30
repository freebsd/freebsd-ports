# New ports collection makefile for:	terminator
# Date created:		2008-03-14
# Whom:			Thomas Hurst <tom@hur.st>
#
# $FreeBSD$
#

PORTNAME=	terminator
PORTVERSION=	0.8.1
CATEGORIES=	x11 python
MASTER_SITES=	https://launchpad.net/terminator/trunk/${PORTVERSION}/+download/ \
		https://hur.st/mirror/terminator/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	Multiple GNOME terminals in one window

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Terminator

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
MAKE_ENV+=	WITHOUT_NLS="yes"
PLIST_SUB+=	NLS="@comment "
.endif

INSTALLS_ICONS=	yes

USE_GNOME=	pygnome2 pygtk2
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte

MAN1=	terminator.1

.include <bsd.port.mk>
