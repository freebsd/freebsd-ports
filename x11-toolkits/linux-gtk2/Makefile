# New ports collection makefile for:	linux-gtk2
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.2.1
PORTREVISION=	0
CATEGORIES=	x11-toolkits linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	GTK+ library, version 2.X, i386 Linux binary

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"binaries under GNU LGPL without accompanying source"
RPM_SET=	gtk2-2.2.1-4.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id; \
		${FIND} * -type f -o -type l > ${PLIST}; \
		${FIND} -d * -type d  | ${SED} -e 's:^:@dirrm :' \
		>> ${PLIST}

.include "../linux-gtk/Makefile"
