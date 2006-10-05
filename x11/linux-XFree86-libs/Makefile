# New ports collection makefile for:	linux-XFree86-libs
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		XFree86-libs
PORTVERSION=		4.3.99.902
PORTREVISION=		7
CATEGORIES=		x11 linux
MASTER_SITES=	${MASTER_SITE_SUSE} \
		ftp://ftp.in2p3.fr/pub/linux/suse/update/9.1/rpm/i586/ \
		ftp://ftp.dit.upm.es/suseupdates/suse-9.1/updates/
MASTER_SITE_SUBDIR=	i386/update/9.1/rpm/i586
PKGNAMEPREFIX=	linux-
DISTNAME=	XFree86-libs-4.3.99.902-43.42.5.i586.rpm
EXTRACT_SUFX=
DIST_SUBDIR=	rpm/i386/suse
EXTRACT_ONLY=

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	XFree86 libraries, Linux binary

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig

CONFLICTS=	linux_base-7* linux_base-deb* linux-xorg-libs*
USE_LINUX_PREFIX=yes
USE_LINUX=	yes
MD5_FILE=	${MASTERDIR}/distinfo.i386
NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
PKGINSTALL=	${WRKDIR}/pkg-install
PLIST=		${WRKDIR}/plist
PLIST_DIRS=	usr/X11R6/lib/X11

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
	@${SED} -e 's|%%LINUXBASE%%|${LINUXBASE}|g ; s|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

do-install:
	@rpm -U --ignorearch --ignoreos --root ${PREFIX} --dbpath /var/lib/rpm \
		 --nodeps --replacepkgs ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		|| ${TRUE}

.include <bsd.port.mk>
