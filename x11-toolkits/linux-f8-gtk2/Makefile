# New ports collection makefile for:	x11-toolkits/linux-f8-gtk2
# Date created:				2008-03-29
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.12.8
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
PKGNAMEPREFIX=	linux-f8-
DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}.${LINUX_RPM_ARCH}.rpm \
		${PORTNAME}-engines-2.12.2-1.fc8.${LINUX_RPM_ARCH}.rpm \
		gtk-murrine-engine-0.52-1.fc7.${LINUX_RPM_ARCH}.rpm \
		gtk-nodoka-engine-0.6.2-1.fc8.${LINUX_RPM_ARCH}.rpm \
		gtk-qt-engine-0.8-6.fc8.${LINUX_RPM_ARCH}.rpm \
		gtk-rezlooks-engine-0.6-5.fc8.${LINUX_RPM_ARCH}.rpm \
		gtk-xfce-engine-2.4.2-1.fc8.${LINUX_RPM_ARCH}.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X (Linux Fedora 8)

CONFLICTS=	linux-gtk2-[0-9]* linux-f10-gtk2-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
# these libraries are required by gtk-query-immodules-2.0 or
# gdk-pixbuf-query-loaders
USE_LINUX_APPS=	atk jpeg pango png tiff xorglibs
LINUX_DIST_VER=	8
RPMVERSION=	2.fc8
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr
SRC_DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}.src.rpm \
		${PORTNAME}-engines-2.12.2-1.fc8.src.rpm \
		gtk-murrine-engine-0.52-1.fc7.src.rpm \
		gtk-nodoka-engine-0.6.2-1.fc8.src.rpm \
		gtk-qt-engine-0.8-6.fc8.src.rpm \
		gtk-rezlooks-engine-0.6-5.fc8.src.rpm \
		gtk-xfce-engine-2.4.2-1.fc8.src.rpm

post-install:
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0-32 > ${PREFIX}/etc/gtk-2.0/i386-redhat-linux-gnu/gtk.immodules
	@chroot ${PREFIX} /usr/bin/gdk-pixbuf-query-loaders-32 > ${PREFIX}/etc/gtk-2.0/i386-redhat-linux-gnu/gdk-pixbuf.loaders

.include <bsd.port.mk>
