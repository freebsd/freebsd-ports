# New ports collection makefile for:	linux-XFree86-libs
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		XFree86-libs
PORTVERSION=		4.3.99.902
CATEGORIES=		x11 linux
MASTER_SITES=		ftp://suse.cs.utah.edu/pub/suse.com/suse/i386/update/9.1/rpm/i586/ \
			ftp://ftp.suse.com/pub/suse/i386/update/9.1/rpm/i586/
PKGNAMEPREFIX=	linux-
DISTNAME=	XFree86-libs-4.3.99.902-43.35.3.i586.rpm
EXTRACT_SUFX=
DIST_SUBDIR=	rpm/i386/suse
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	XFree86 libraries, Linux/i386 binary

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8

CONFLICTS=	linux_base-6* linux_base-7* linux_base-deb* linux_base-gentoo*
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
PLIST_DIRS=	usr/X11R6/lib/X11
PREFIX=		${LINUXBASE}

pre-install:
	@${RM} -f ${PLIST}
.for ii in libXss.so.1 libxkbui.so.1 libxkbfile.so.1 libfontenc.so.1 libXxf86rush.so.1 libXvMC.so.1 libXinerama.so.1 libXfontcache.so.1 libXRes.so.1 libVncExt.so.2 libI810XvMC.so.1 libGLw.so.1 libFS.so.6
	@${ECHO_CMD} usr/X11R6/lib/${ii} >> ${PLIST}
.endfor
	@${RM} -rf ${WRKDIR}/tmp
	@${MKDIR} ${WRKDIR}/tmp
	@cd ${WRKDIR}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} | cpio -id; \
		${FIND} * -type f -o -type l >> ${PLIST} ; \
		${FIND} -d usr/X11R6/lib/X11/locale -type d  | \
			${SED} -e 's:^:@dirrm :' >> ${PLIST}
post-install:
	@${RM} -f ${LINUXBASE}/etc/ld.so.cache
	@${FIND} ${LINUXBASE} -name lib -type d | ${SED} 's:${LINUXBASE}::g' \
		> ${LINUXBASE}/etc/ld.so.conf
	@chroot ${LINUXBASE} sbin/ldconfig

do-install:
	@rpm -U --ignorearch --ignoreos --root ${PREFIX} --dbpath /var/lib/rpm \
		 --nodeps --replacepkgs ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		|| ${TRUE}

.include <bsd.port.mk>
