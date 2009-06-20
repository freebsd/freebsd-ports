# New ports collection makefile for:	x11-toolkits/linux-f10-openmotif
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.3.2
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	ftp://ftp.motifzone.com/%SUBDIR%/ \
		ftp://ftp.ics.com/openmotif/%SUBDIR%/
MASTER_SITE_SUBDIR=	2.3/${PORTVERSION}
PKGNAMEPREFIX=	linux-f10-
EXTRACT_SUFX=	-1.fc10.i386.rpm
DIST_SUBDIR=	rpm

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Motif toolkit Linux libraries

CONFLICTS=	linux-openmotif-[0-9]* linux-f8-openmotif-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	10
USE_LDCONFIG=	yes
SRC_DISTFILES=
MD5_FILE=	${MASTERDIR}/distinfo.i386

post-extract:
		@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/bin ${WRKSRC}/usr/include \
			${WRKSRC}/usr/share ${WRKSRC}/usr/lib/X11

.include <bsd.port.mk>
