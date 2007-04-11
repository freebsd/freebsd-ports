# New ports collection makefile for:	xfce4-taskbar-plugin
# Date created:		5 May 2005
# Whom:			DaJoob
#
# $FreeBSD$
#

PORTNAME=	xfce4-taskmanager
PORTVERSION=	0.4.0.r2
PORTREVISION=	5
CATEGORIES=	x11 xfce
MASTER_SITES=	http://xfce4-taskmanager.nebulon.de/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}
DIST_SUBDIR=	xfce4

MAINTAINER=	DaJoob@dajoob.com
COMMENT=	A task manager for XFCE

CONFIGURE_ENV=	PKG_CONFIG_PATH=${X11BASE}/libdata/pkgconfig:${LOCALBASE}/libdata/pkgconfig

GNU_CONFIGURE=	yes
USE_BZIP=	yes
USE_GCC=	3.4+
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui
USE_XLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|linux|freebsd|g; s|^CFLAGS = |&-lkvm -lm |' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
