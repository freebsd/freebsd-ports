# New ports collection makefile for:	linux-pango
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits linux

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux pango binary

# these libraries are required by pango-querymodules
BUILD_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

RUN_DEPENDS=	${BUILD_DEPENDS}

USE_XLIB=	yes
BASEVERSION=	9
ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist
RPM_SET=	pango-1.2.1-3.i386.rpm

post-install:
	@${BRANDELF} -t Linux ${PREFIX}/usr/bin/pango-querymodules
	@${PREFIX}/usr/bin/pango-querymodules > ${PREFIX}/etc/pango/pango.modules

.include "../linux-gtk/Makefile"
