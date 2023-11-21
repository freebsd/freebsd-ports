DISTVERSION=	0.3.2
PORTREVISION=	1
PKGNAMESUFFIX=	${GH_PROJECT:S/${PORTNAME}//}

PATCHFILES+=	c47aa61c6492.patch:-p1 # https://github.com/WillPower3309/swayfx/pull/209

COMMENT=	Sway, but with eye candy!
WWW=		https://github.com/WillPower3309/swayfx

MASTERDIR=	${.CURDIR}/../sway
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo

GH_ACCOUNT=	WillPower3309
GH_PROJECT=	swayfx
USE_GL=		egl

CONFLICTS_INSTALL=	${PORTNAME} ${PORTNAME}-devel

.include "${MASTERDIR}/Makefile"
