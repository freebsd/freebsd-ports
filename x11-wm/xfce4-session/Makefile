# New ports collection makefile for:	xfce4-session
# Date created:		2003-10-30
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-session
PORTVERSION=	4.4.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITES_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Session manager for the Xfce 4 desktop environment

BUILD_DEPENDS=	iceauth:${X_CLIENTS_PORT}
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libgui libmcs libutil mcsmanager
USE_XLIB=	yes

MAN1=		xfce4-session.1 xfce4-session-logout.1

.include <bsd.port.mk>
