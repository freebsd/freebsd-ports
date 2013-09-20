# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openmotif
PORTVERSION=	2.3.3
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	ftp://ftp.ics.com/openmotif/2.3/${PORTVERSION}/ \
		CRITICAL/rpm
PKGNAMEPREFIX=	linux-f10-
EXTRACT_SUFX=	-1.fc10.i386.rpm
DIST_SUBDIR=	rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Motif toolkit Linux libraries

CONFLICTS=	linux-openmotif-[0-9]* linux-f8-openmotif-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	10
USE_LDCONFIG=	yes
SRC_DISTFILES=
DISTINFO_FILE=	${MASTERDIR}/distinfo.i386

NO_STAGE=	yes
post-extract:
		@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/bin ${WRKSRC}/usr/include \
			${WRKSRC}/usr/share ${WRKSRC}/usr/lib/X11

.include <bsd.port.mk>
