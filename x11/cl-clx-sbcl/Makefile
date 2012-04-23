# New ports collection makefile for:	cl-clx-sbcl
# Date created:				7 Oct 2010
# Whom:					Anonymous
#
# $FreeBSD$

PORTREVISION=	2
DISTFILES=	# none

MASTERDIR=	${.CURDIR}/../../x11/cl-clx

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/clx/clx.asd:${PORTSDIR}/x11/cl-clx
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/clx/clx.asd:${PORTSDIR}/x11/cl-clx

USE_ASDF_FASL=	yes
FASL_BUILD=	yes
FASL_TARGET=	sbcl

PLIST=		${.CURDIR}/pkg-plist

BROKEN =	: Changes in sbcl 1.0.55 have exposed problems in ${ASDF_PATHNAME}/depdefs.lisp

.include "${MASTERDIR}/Makefile"
