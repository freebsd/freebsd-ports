# New ports collection makefile for:	linux-pango
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Linux/i386 pango binary

# these libraries are required by pango-querymodules
RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXft.so.2:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig \
		${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"binary under GNU LGPL without accompanying source"
RPM_SET=	pango-1.2.1-3.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${ECHO_CMD} etc/pango/pango.modules > ${PLIST}
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | ${CPIO} -id; \
		${FIND} * -type f -o -type l >> ${PLIST}; \
		${FIND} -d * -type d | ${GREP} pango | \
		${SED} -e 's:^:@dirrm :' >> ${PLIST}

post-install:
	${PREFIX}/usr/bin/pango-querymodules > ${PREFIX}/etc/pango/pango.modules

.include "../linux-gtk/Makefile"
