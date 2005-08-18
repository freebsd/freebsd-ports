# New ports collection makefile for:	linux-gtk2
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.2.1
PORTREVISION=	5
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	http://www.infostrategique.com/linuxrpms/legacy/9/

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X, Linux binary

# these libraries are required by gtk-query-immodules-2.0 or
# gdk-pixbuf-query-loaders
BUILD_DEPENDS+=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libpng12.so.0.1.2.7:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libtiff.so.3.6.1:${PORTSDIR}/graphics/linux-tiff \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0.200.1:${PORTSDIR}/x11-toolkits/linux-pango
RUN_DEPENDS+=	${BUILD_DEPENDS}

DIST_SUBDIR=	rpm/i386/rh9
ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist
USE_XLIB=	yes
RESTRICTED=	"binaries under GNU LGPL without accompanying source"
RPM_SET=	gtk2-2.2.1-4.1.legacy.i386.rpm

post-install:
.for ii in gdk-pixbuf-query-loaders gtk-demo gtk-query-immodules-2.0 testgtk testtext
	@${BRANDELF} -t Linux ${PREFIX}/usr/bin/${ii}
.endfor
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
	@chroot ${PREFIX} /usr/bin/gdk-pixbuf-query-loaders > ${PREFIX}/etc/gtk-2.0/gdk-pixbuf.loaders

.include "../linux-gtk/Makefile"
