# New ports collection makefile for:	linux-XFree86-libs
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		XFree86-libs
PORTVERSION=		4.3.0
PORTREVISION=		0
CATEGORIES=		x11 linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	updates/9/en/os/i386

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	XFree86 libraries, Linux/i386 binary

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RPM_SET=	XFree86-libs-4.3.0-2.90.43.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id; \
		${FIND} * -type f -o -type l > ${PLIST}
.for ii in \
	usr/X11R6/lib/X11/locale/lib/common \
	usr/X11R6/lib/X11/locale/lib \
	usr/X11R6/lib/X11/locale \
	usr/X11R6/lib/X11
	${ECHO_CMD} @dirrm ${ii} >> ${PLIST}
.endfor

.include "../../x11-toolkits/linux-gtk/Makefile"
