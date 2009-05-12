# New ports collection makefile for:   linux-openmotif
# Date created:                2001-09-24
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.3.2
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	ftp://ftp.motifzone.com/%SUBDIR%/ \
		ftp://ftp.ics.com/openmotif/%SUBDIR%/
MASTER_SITE_SUBDIR=	2.3/${PORTVERSION}
PKGNAMEPREFIX=	linux-f8-
EXTRACT_SUFX=	-1.fc8.i386.rpm
DIST_SUBDIR=	rpm

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Motif toolkit Linux libraries

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
USE_LDCONFIG=	yes
SRC_DISTFILES=
MD5_FILE=	${MASTERDIR}/distinfo.i386

post-extract:
		@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/bin ${WRKSRC}/usr/include \
			${WRKSRC}/usr/share ${WRKSRC}/usr/lib/X11

.include <bsd.port.mk>
