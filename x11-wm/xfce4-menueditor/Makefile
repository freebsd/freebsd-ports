# New ports collection makefile for:	xfce4-menueditor
# Date created:		2004-01-22
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-menueditor
PORTVERSION=	1.05
PORTREVISION=	2
CATEGORIES=	x11-wm xfce
MASTER_SITES=	http://users.skynet.be/p0llux/files/ \
		http://matt.nerim.net/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	matt@bsdfly.org
COMMENT=	Menu Editor for the XFce desktop environment

LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui

USE_GNOME=	gtk20 libxml2
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

CONFIGURE_ARGS=		--disable-cvs

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
