# New ports collection makefile for: linux-gtk
# Date created:         8 April 2000
# Whom:                 sada@FreeBSD.org
# Based on:		emulators/linux_base by marcel@FreeBSD.org
#			& graphics/xmovie by sanpei@sanpei.org
#
# $FreeBSD$
#

PORTNAME?=	gtk
PORTVERSION?=	1.2
PORTREVISION=	1
CATEGORIES?=	x11-toolkits linux
MASTER_SITES=	${RPM_MIRRORS:S/__DIR__/${STDDIR}/g}
PKGNAMEPREFIX=	linux-
DISTFILES=	${RPM_SET}

MAINTAINER?=	ports@FreeBSD.org

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
USE_LINUX_PREFIX=	yes

ONLY_FOR_ARCHS=	i386 alpha
DIST_SUBDIR=	rpm
EXTRACT_ONLY=
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
PLIST=		${PKGDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

RPM_MIRRORS=	ftp://ftp.freesoftware.com/pub/linux/redhat/old-releases/__DIR__/ \
		ftp://ftp.freesoftware.com/pub/linux/redhat/__DIR__/
STDDIR=		redhat-6.1/${MACHINE_ARCH}/RedHat/RPMS
UPDDIR=		updates/6.1/${MACHINE_ARCH}
.if (${MACHINE_ARCH} == "i386")
RPM_SET?=	gtk+-1.2.5-2.${MACHINE_ARCH}.rpm
.elif (${MACHINE_ARCH} == "alpha")
RPM_SET?=	gtk+-1.2.6-1.${MACHINE_ARCH}.rpm
.endif
DBPATH=		/var/lib/rpm
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

do-install:
	@for R in ${RPM_SET}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done

.include <bsd.port.mk>
