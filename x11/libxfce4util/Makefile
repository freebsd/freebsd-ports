# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	libxfce4util
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	http://www.xfce.org/archive/xfce-${PORTVERSION}/src/ \
                ftp://ftp.berlios.de/pub/xfce-goodies/${PORTVERSION}/xfce-${PORTVERSION}/src/ \
                http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/${PORTVERSION}/ \
                http://www.efd.lth.se/~c03bk/xfce4/mirror/tarballs/${PORTVERSION}/
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 library with non-graphical helper functions

USE_GNOME=	glib20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/${PORTNAME}/Makefile.in

.include <bsd.port.mk>
