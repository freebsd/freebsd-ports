# New ports collection makefile for:	xfce4-menueditor
# Date created:		2004-01-22
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-menueditor
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	http://users.skynet.be/p0llux/files/ \
		http://www.bsd-blax.org/ports/mirrors/

MAINTAINER=	matt@rimasec.net
COMMENT=	Menu Editor for the XFce desktop environment

LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui

PLIST_FILES=	bin/xfce4-menueditor
USE_GNOME=	gtk20 libxml2
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

CONFIGURE_ARGS=		--disable-cvs

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
