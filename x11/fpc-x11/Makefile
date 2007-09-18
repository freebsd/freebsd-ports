# New ports collection makefile for:	fpc-x11
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	x11 lang
PKGNAMESUFFIX=	-x11

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to X windows server

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	X11	"Install X libraries"	on

.include "${MASTERDIR}/Makefile"
