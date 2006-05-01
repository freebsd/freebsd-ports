# New ports collection makefile for:	linux-gtk2
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.4.14
PORTREVISION=	4
CATEGORIES=	x11-toolkits linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-4.fc3.3

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X, Linux binary

# these libraries are required by gtk-query-immodules-2.0 or
# gdk-pixbuf-query-loaders
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libpng12.so.0:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango

ONLY_FOR_ARCHS=	i386 amd64
USE_XLIB=	yes
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
PLIST_SUB=	LIBVERSION="400.14" PORTVERSION="${PORTVERSION}"

post-install:
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0-32 > ${PREFIX}/etc/gtk-2.0/i386-redhat-linux-gnu/gtk.immodules
	@chroot ${PREFIX} /usr/bin/gdk-pixbuf-query-loaders-32 > ${PREFIX}/etc/gtk-2.0/i386-redhat-linux-gnu/gdk-pixbuf.loaders

.include <bsd.port.mk>
