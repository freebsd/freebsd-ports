# New ports collection makefile for:	linux-XFree86-libs
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		XFree86-libs
PORTVERSION=		4.3.0
PORTREVISION=		2
CATEGORIES=		x11 linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	updates/9/en/os/i386
PKGNAMEPREFIX=	linux-
DISTNAME=	XFree86-libs-4.3.0-2.90.43.i386.rpm
EXTRACT_SUFX=
DIST_SUBDIR=	rpm
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	XFree86 libraries, Linux/i386 binary

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8

BASEVERSION=	9
CONFLICTS=	linux_base-6* linux_base-7* linux_base-deb* linux_base-gentoo*
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
PREFIX=		${LINUXBASE}

pre-install:
	@${RM} -rf ${WRKSRC}/tmp
	@${MKDIR} ${WRKSRC}/tmp
	@cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} | cpio -id; \
		${FIND} * -type f -o -type l > ${PLIST}
.for ii in X11/locale/lib/common X11/locale/lib X11/locale X11
	@${ECHO_CMD} @dirrm usr/X11R6/lib/${ii} >> ${PLIST}
.endfor

post-install:
	@${RM} -f ${LINUXBASE}/etc/ld.so.cache
	@${FIND} ${LINUXBASE} -name lib -type d | ${SED} 's:${LINUXBASE}::g' \
		> ${LINUXBASE}/etc/ld.so.conf
	@chroot ${LINUXBASE} sbin/ldconfig

do-install:
	@rpm -U --ignoreos --root ${PREFIX} --dbpath /var/lib/rpm --nodeps \
		--replacepkgs ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} || ${TRUE}

.include <bsd.port.mk>
