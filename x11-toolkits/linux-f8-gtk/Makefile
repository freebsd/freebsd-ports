# New ports collection makefile for: linux-gtk
# Version required:     1.2.x
# Date created:         8 April 2000
# Whom:                 sada@FreeBSD.org
# Based on:		emulators/linux_base by marcel@FreeBSD.org
#			& graphics/xmovie by sanpei@sanpei.org
#
# $FreeBSD$
#

PORTNAME?=	gtk
PORTVERSION?=	1.2
CATEGORIES?=	x11-toolkits linux
MASTER_SITES=	${RPM_MIRRORS:S/__DIR__/${STDDIR}/g}
PKGNAMEPREFIX=	linux-
DISTFILES=	${RPM_SET}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	rpm:${PORTSDIR}/misc/rpm
RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

DIST_SUBDIR=	rpm
EXTRACT_ONLY=
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=	yes
ONLY_FOR_ARCHS=	i386
PREFIX=		/compat/linux

RPM_MIRRORS=	ftp://ftp.freesoftware.com/pub/linux/redhat/__DIR__/
STDDIR=		redhat-6.1/${MACHINE_ARCH}/RedHat/RPMS
UPDDIR=		updates/6.1/${MACHINE_ARCH}
RPM_SET?=	gtk+-1.2.5-2.${MACHINE_ARCH}.rpm
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
