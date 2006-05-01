# New ports collection makefile for:	linux-pango
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-7

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux pango binary

# these libraries are required by pango-querymodules
RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
PLIST_SUB+=	LIBVERSION="600.0" PORTVERSION="${PORTVERSION}"

post-install:
	@${PREFIX}/usr/bin/pango-querymodules-32 > ${PREFIX}/etc/pango/i386-redhat-linux-gnu/pango.modules

.include <bsd.port.mk>
