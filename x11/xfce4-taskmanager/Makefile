# New ports collection makefile for:	xfce4-taskbar-plugin
# Date created:		5 May 2005
# Whom:			DaJoob
#
# $FreeBSD$
#

PORTNAME=	xfce4-taskmanager
PORTVERSION=	0.4.0.r2
PORTREVISION=	16
CATEGORIES=	x11 xfce
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A task manager for XFCE

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui

post-patch:
	@${REINPLACE_CMD} -e 's|linux|freebsd|g; s|^CFLAGS = |&-lkvm -lm |' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
