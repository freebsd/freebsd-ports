# New ports collection makefile for:	linux-pango
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.6.0
PORTREVISION=	0
CATEGORIES=	x11-toolkits linux

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux pango binary
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	3/i386/os/Fedora/RPMS

# these libraries are required by pango-querymodules
BUILD_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

RUN_DEPENDS=	${BUILD_DEPENDS}

USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist
RPM_SET=	pango-${PORTVERSION}-7.i386.rpm
PLIST_SUB+=	LIBVERSION="600.0" PORTVERSION="${PORTVERSION}"

post-install:
	@${BRANDELF} -t Linux ${PREFIX}/usr/bin/pango-querymodules-32
	@${PREFIX}/usr/bin/pango-querymodules-32 > ${PREFIX}/etc/pango/i386-redhat-linux-gnu/pango.modules

.include "../linux-gtk/Makefile"
