# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	x11 lang
PKGNAMESUFFIX=	-x11

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to X windows server

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	X11
X11_DESC=	Install X libraries
OPTIONS_DEFAULT=	X11

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
