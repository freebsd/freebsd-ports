# New ports collection makefile for:	linux-gtk2
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.2.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	GTK+ library, version 2.X, i386 Linux binary

# these libraries are required by gtk-query-immodules-2.0 or
# gdk-pixbuf-query-loaders
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libpng12.so.0:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libtiff.so.3.5:${PORTSDIR}/graphics/linux-tiff \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"binaries under GNU LGPL without accompanying source"
RPM_SET=	gtk2-2.2.1-4.i386.rpm

pre-install:
	${RM} -f ${PLIST}
.for ii in gtk.immodules gdk-pixbuf.loaders
	${ECHO_CMD} etc/gtk-2.0/${ii} >> ${PLIST}
.endfor
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | ${CPIO} -id; \
		${FIND} * -type f -o -type l >> ${PLIST}; \
		${FIND} -d * -type d | ${GREP} -E 'gtk|themes' | \
		${SED} -e 's:^:@dirrm :' >> ${PLIST}; \
		${FIND} -d * -type d | ${GREP} locale | \
		${SED} -e 's:^:@unexec rmdir %D/:;s:$$: 2>/dev/null || true:' >> ${PLIST}

post-install:
	${PREFIX}/usr/bin/gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
	${PREFIX}/usr/bin/gdk-pixbuf-query-loaders > ${PREFIX}/etc/gtk-2.0/gdk-pixbuf.loaders

.include "../linux-gtk/Makefile"
