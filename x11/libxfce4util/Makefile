# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	libxfce4util
PORTVERSION=	3.99.2
CATEGORIES=	x11 xfce
MASTER_SITES=	http://www.xfce.org/archive/xfce4-rc2/src/ \
		ftp://ftp.unix-ag.org/user/bmeurer/xfce4/rc2/separate/ \
		http://usuarios.lycos.es/xfce4/tarballs/rc2/separate/ \
		http://linux.imp.mx/xfce4/rc2/xfce4-rc2/src/
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
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
