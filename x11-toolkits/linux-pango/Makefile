# New ports collection makefile for:	linux-pango
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.10.2
DISTVERSIONSUFFIX=	-1.gst.1.4
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	http://gstreamer.freedesktop.org/pkg/%SUBDIR%/ CENKES/myports
MASTER_SITE_SUBDIR=	${LINUX_DIST}/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/RPMS.gst010
MASTER_SITE_SRC_SUBDIR=	${LINUX_DIST}/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/SRPMS.gst010

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux pango binary

# these libraries are required by pango-querymodules
.if !defined(OVERRIDE_LINUX_BASE_PORT) || \
    (${OVERRIDE_LINUX_BASE_PORT} != "fc6" && \
    ${OVERRIDE_LINUX_BASE_PORT} != "f7" && \
    ${OVERRIDE_LINUX_BASE_PORT} != "f8")
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2
.endif
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libcairo.so.2.2.3:${PORTSDIR}/graphics/linux-cairo \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
PLIST_SUB+=	LIBVERSION="1001.1" PORTVERSION="${PORTVERSION}"

post-install:
	@${PREFIX}/usr/bin/pango-querymodules-32 > ${PREFIX}/etc/pango/i686-redhat-linux-gnu/pango.modules

.include <bsd.port.mk>
