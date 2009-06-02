# New ports collection makefile for:	linux-gtk2
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.6.10
PORTREVISION=	3
CATEGORIES=	x11-toolkits linux
DISTFILES=	${PORTNAME}-${PORTVERSION}-2.fc4.4.${LINUX_RPM_ARCH}.rpm \
		${PORTNAME}-engines-2.6.3-2.${LINUX_RPM_ARCH}.rpm

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X, Linux binary

CONFLICTS=	linux-f8-gtk2-[0-9]* linux-f10-gtk2-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
# these libraries are required by gtk-query-immodules-2.0 or
# gdk-pixbuf-query-loaders
USE_LINUX_APPS=	atk jpeg pango png tiff xorglibs
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
PLIST_SUB=	LIBVERSION="600.10" PORTVERSION="${PORTVERSION}"
SRC_DISTFILES=	${PORTNAME}-${PORTVERSION}-2.fc4.4.src.rpm \
		${PORTNAME}-engines-2.6.3-2.src.rpm

post-install:
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0-32 > ${PREFIX}/etc/gtk-2.0/i386-redhat-linux-gnu/gtk.immodules
	@chroot ${PREFIX} /usr/bin/gdk-pixbuf-query-loaders-32 > ${PREFIX}/etc/gtk-2.0/i386-redhat-linux-gnu/gdk-pixbuf.loaders

.include <bsd.port.mk>
