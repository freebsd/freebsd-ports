# ex:ts=8
# New ports collection makefile for:	motif
# Date created:		5 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	open-motif-devel
PORTVERSION=	2.1.30
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://openmotif.opengroup.org/pub/openmotif/R2.1.30/binaries/metrolink/  \
		ftp://ftp.opengroup.org/pub/openmotif/R2.1.30/binaries/metrolink/  \
		ftp://ftp.isca.uiowa.edu/pub/mirrors/openmotif/binaries/metrolink/  \
		ftp://ftp.kddlabs.co.jp:/X11/openmotif/binaries/metrolink/
DISTNAME=	openmotif-devel-${PORTVERSION}-4_MLI
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org

ONLY_FOR_ARCHS=	i386
PREFIX?=	/	# will install into ${PREFIX}/usr/X11R6
NO_MTREE=	yes
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	# don't exact the tarball
NO_BUILD=	binary distrubition
NO_PKG_REGISTER=do-install: target will take care of this

do-install:
	@pkg_add -f -p ${PREFIX} ${DISTDIR}/${DISTFILES}
	@${MV} -v ${PKG_DBDIR}/${DISTNAME} ${PKG_DBDIR}/${PKGNAME}

#	shouldn't this be covered by "NO_PKG_REGISTER" ??
generate-plist:
	@${DO_NADA}

do-package:
	@${ECHO_MSG} "===>  Building package for ${PKGNAME}"
	@if [ -d ${PACKAGES} ]; then \
		if [ ! -d ${PKGREPOSITORY} ]; then \
			if ! ${MKDIR} ${PKGREPOSITORY}; then \
				${ECHO_MSG} ">> Can't create directory ${PKGREPOSITORY}."; \
				exit 1; \
			fi; \
		fi; \
	fi
	@${CP} -p ${DISTDIR}/${DISTFILES} ${PKGFILE}

.include <bsd.port.mk>
