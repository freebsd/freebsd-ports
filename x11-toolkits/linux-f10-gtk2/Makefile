# New ports collection makefile for:	linux-gtk2
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	GTK+ library, version 2.X, i386 Linux binary

BUILD_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"binaries under GNU LGPL without accompanying source"
RPM_SET=	gtk2-2.2.1-4.i386.rpm

BROKEN=		"Build fails"

pre-install:
	${RM} -f ${PLIST}
.for ii in gtk.immodules gdk-pixbuf.loaders
	${ECHO_CMD} etc/gtk-2.0/${ii} >> ${PLIST}
.endfor
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio.pl < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id; \
		${FIND} * -type f -o -type l >> ${PLIST}; \
		${FIND} -d * -type d | ${GREP} -E 'locale|gtk|themes' | \
		${SED} -e 's:^:@dirrm :' >> ${PLIST}

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtk.immodules ${PREFIX}/etc/gtk-2.0/
	${TOUCH} ${PREFIX}/etc/gtk-2.0/gdk-pixbuf.loaders

.include "../linux-gtk/Makefile"
