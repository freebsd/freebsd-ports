# New ports collection makefile for:	open-motif-jdk
# Date created:				31 January 2005
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-jdk

MAINTAINER=	phantom@FreeBSD.org

.if defined(WITH_JDK_PATCH)
EXTRA_PATCHES+=	${WITH_JDK_PATCH}
.else
IGNORE=		"cannot be built separately"
.endif

WITHOUT_OPENMOTIF_DEMOS=	YES
WITHOUT_OPENMOTIF_MANUALS=	YES

MASTERDIR=	${.CURDIR}/../open-motif

.include "${MASTERDIR}/Makefile"
