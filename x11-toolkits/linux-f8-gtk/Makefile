# New ports collection makefile for: linux-gtk
# Date created:         8 April 2000
# Whom:                 sada@FreeBSD.org
# Based on:		emulators/linux_base by marcel@FreeBSD.org
#			& multimedia/xmovie by sanpei@sanpei.org
#
# $FreeBSD$
#

PORTNAME?=	gtk
PORTVERSION?=	1.2
PORTREVISION?=	4
CATEGORIES?=	x11-toolkits linux
MASTER_SITES?=	${RPM_MIRRORS:S/__DIR__/${STDDIR}/g}
PKGNAMEPREFIX=	linux-
DISTFILES=	${RPM_SET}

MAINTAINER?=	freebsd-emulation@FreeBSD.org
COMMENT?=	RPM of the Gtk lib

BUILD_DEPENDS+=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS?=	${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs

USE_LINUX_PREFIX=	yes
USE_LINUX=	yes

ONLY_FOR_ARCHS?=	i386 alpha
DIST_SUBDIR?=	rpm
EXTRACT_ONLY=
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
PLIST?=		${PKGDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE?=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

# Let's avoid hardcoding 'en' as the language.
LANG=		en
# Set the version of linux_base
BASEVERSION?=	7.1
RPM_MIRRORS=	\
	ftp://ftp.redhat.com/pub/redhat/__DIR__/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/__DIR__/
STDDIR=		linux/${BASEVERSION}/${LANG}/os/${MACHINE_ARCH}/RedHat/RPMS
UPDDIR=		linux/updates/${BASEVERSION}/${LANG}/os/${MACHINE_ARCH}
.if (${MACHINE_ARCH} == "i386")
RPM_SET?=	gtk+-1.2.9-4.${MACHINE_ARCH}.rpm
.elif (${MACHINE_ARCH} == "alpha")
RPM_SET?=	gtk+-1.2.9-4.${MACHINE_ARCH}.rpm
.endif
DBPATH=		/var/lib/rpm
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

do-install:
	@for R in ${RPM_SET}; do \
		${ECHO_MSG} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R || true ; \
	done

new-plist:
	@${RM} -rf ${WRKSRC}/tmp
	@${MKDIR} ${WRKSRC}/tmp
	@cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | ${CPIO} -id; \
		${FIND} * -type f -o -type l > ${PLIST}.new; \
		${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' \
		>> ${PLIST}.new

.include <bsd.port.mk>
