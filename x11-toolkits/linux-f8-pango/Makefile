# New ports collection makefile for:	linux-pango
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.2.1
PORTREVISION=	0
CATEGORIES=	x11-toolkits linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Linux/i386 pango binary

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio \
	${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"binary under GNU LGPL without accompanying source"
RPM_SET=	pango-1.2.1-3.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id; \
		${FIND} * -type f -o -type l > ${PLIST}; \
		${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' >> ${PLIST}

post-install:
	${LINUXBASE}/usr/bin/pango-querymodules >\
		${LINUXBASE}/etc/pango/pango.modules

.include "../linux-gtk/Makefile"
