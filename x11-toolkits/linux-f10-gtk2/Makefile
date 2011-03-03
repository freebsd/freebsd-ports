# New ports collection makefile for:	x11-toolkits/linux-f10-gtk2
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.14.7
PORTREVISION=	3
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}.${LINUX_RPM_ARCH}.rpm \
		${PORTNAME}-engines-2.16.1-1.fc10.${LINUX_RPM_ARCH}.rpm \
		gtk-murrine-engine-0.53.1-3.fc10.${LINUX_RPM_ARCH}.rpm \
		gtk-nodoka-engine-0.7.2-1.fc10.${LINUX_RPM_ARCH}.rpm \
		gtk-qt-engine-1.1-2.fc10.${LINUX_RPM_ARCH}.rpm \
		gtk-rezlooks-engine-0.6-6.fc9.${LINUX_RPM_ARCH}.rpm \
		gtk-xfce-engine-2.4.3-1.fc10.${LINUX_RPM_ARCH}.rpm \
		pixman-0.12.0-3.fc10.${LINUX_RPM_ARCH}.rpm \
		jasper-libs-1.900.1-8.fc9.${LINUX_RPM_ARCH}.rpm

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X (Linux Fedora 10)

CONFLICTS=	linux-gtk2-[0-9]* linux-f8-gtk2-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
# these libraries are required by gtk-query-immodules-2.0 or
# gdk-pixbuf-query-loaders
USE_LINUX_APPS=	atk jpeg pango png tiff xorglibs
LINUX_DIST_VER=	10
RPMVERSION=	9.fc10
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr
SRC_DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}.src.rpm \
		${PORTNAME}-engines-2.16.1-1.fc10.src.rpm \
		gtk-murrine-engine-0.53.1-3.fc10.src.rpm \
		gtk-nodoka-engine-0.7.2-1.fc10.src.rpm \
		gtk-qt-engine-1.1-2.fc10.src.rpm \
		gtk-rezlooks-engine-0.6-6.fc9.src.rpm \
		gtk-xfce-engine-2.4.3-1.fc10.src.rpm \
		pixman-0.12.0-3.fc10.src.rpm \
		jasper-1.900.1-8.fc9.src.rpm

post-install:
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0-32 > ${PREFIX}/etc/gtk-2.0/i386-redhat-linux-gnu/gtk.immodules
	@chroot ${PREFIX} /usr/bin/gdk-pixbuf-query-loaders-32 > ${PREFIX}/etc/gtk-2.0/i386-redhat-linux-gnu/gdk-pixbuf.loaders

.include <bsd.port.mk>
