# New ports collection makefile for:	cl-clx-sbcl
# Date created:				7 Oct 2010
# Whom:					Anonymous
#
# $FreeBSD$

DISTFILES=	# none

MASTERDIR=	${.CURDIR}/../../x11/cl-clx

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/clx/clx.asd:${PORTSDIR}/x11/cl-clx
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/clx/clx.asd:${PORTSDIR}/x11/cl-clx

USE_ASDF_FASL=	yes
FASL_BUILD=	yes
FASL_TARGET=	sbcl

.include "${MASTERDIR}/Makefile"
