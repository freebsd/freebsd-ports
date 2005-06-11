# New ports collection makefile for:	linux-gtk2
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	2.2.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	http://www.infostrategique.com/linuxrpms/legacy/9/

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X, Linux binary

# these libraries are required by gtk-query-immodules-2.0 or
# gdk-pixbuf-query-loaders
BUILD_DEPENDS+=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
		${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libpng12.so.0.1.2.7:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libtiff.so.3.6.1:${PORTSDIR}/graphics/linux-tiff \
		${LINUXBASE}/usr/lib/libpango-1.0.so.0.200.1:${PORTSDIR}/x11-toolkits/linux-pango
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${BUILD_DEPENDS}

DIST_SUBDIR=	rpm/i386/rh9
NO_MTREE=	yes
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RESTRICTED=	"binaries under GNU LGPL without accompanying source"
RPM_SET=	gtk2-2.2.1-4.1.legacy.i386.rpm

pre-install:
	${RM} -f ${PLIST}
.for ii in gtk.immodules gdk-pixbuf.loaders
	${ECHO_CMD} etc/gtk-2.0/${ii} >> ${PLIST}
.endfor
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
	rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | ${CPIO} -id; \
		${FIND} * -type f -o -type l >> ${PLIST}; \
		${FIND} -d * -type d | ${GREP} -E 'gtk|themes' | \
		${SED} -e 's:^:@dirrm :' >> ${PLIST}; \
		${FIND} -d * -type d | ${GREP} locale | \
		${SED} -e 's:^:@unexec rmdir %D/:;s:$$: 2>/dev/null || true:' \
			>> ${PLIST}

post-install:
.for ii in gdk-pixbuf-query-loaders gtk-demo gtk-query-immodules-2.0 testgtk testtext
	@${BRANDELF} -t Linux ${PREFIX}/usr/bin/${ii}
.endfor
	@chroot ${PREFIX} /usr/bin/gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
	@chroot ${PREFIX} /usr/bin/gdk-pixbuf-query-loaders > ${PREFIX}/etc/gtk-2.0/gdk-pixbuf.loaders

.include "../linux-gtk/Makefile"
