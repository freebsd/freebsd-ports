# $FreeBSD$

DISTVERSIONPREFIX=	v
DISTVERSION=	1.6-2
PORTREVISION=	0
PKGNAMESUFFIX=	-effects

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	eb2ae6f09c2e.patch:-p1 # https://github.com/mortie/swaylock-effects/pull/35

COMMENT?=	Screen locker for Wayland with fancy effects

MASTERDIR=	${.CURDIR}/../swaylock
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo

GH_ACCOUNT=	mortie
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

.include "${MASTERDIR}/Makefile"
