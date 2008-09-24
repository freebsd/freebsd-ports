# New ports collection makefile for:	terminator
# Date created:		2008-03-14
# Whom:			Thomas Hurst <tom@hur.st>
#
# $FreeBSD$
#

PORTNAME=	terminator
PORTVERSION=	0.11
CATEGORIES=	x11 python
MASTER_SITES=	https://launchpad.net/terminator/trunk/${PORTVERSION}/+download/ \
		http://hur.st/mirror/terminator/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	Multiple GNOME terminals in one window

OPTIONS=	NLS	"Native language support" 	on \
		GCONF	"Use GNOME Terminal settings"	on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Terminator

INSTALLS_ICONS=	yes

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.ifdef(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
PYSETUP+=	--without-gettext --without-icon-cache
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

post-patch:
	@${REINPLACE_CMD} -e 's/0\.10/0.11/' ${WRKSRC}/terminatorlib/version.py

.include <bsd.port.post.mk>
