# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfm
PKGNAMESUFFIX=	-extra

MAINTAINER=	horia@racoviceanu.com
COMMENT=	LibFM-Extra library

LICENSE=	LGPL21

MASTERDIR=	${.CURDIR}/../${PORTNAME}

DESCR=		${.CURDIR}/pkg-descr
FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

USE_LDCONFIG=	yes

EXTRA_ONLY=	yes

OPTIONS_EXCLUDE=DOCS NLS

.include "${MASTERDIR}/Makefile"
