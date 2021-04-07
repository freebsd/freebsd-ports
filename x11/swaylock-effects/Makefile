DISTVERSIONPREFIX=	v
DISTVERSION=	1.6-3
PORTREVISION=	1
PKGNAMESUFFIX=	-effects

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ea4b63d8fff3.patch:-p1 # https://github.com/mortie/swaylock-effects/pull/37
PATCHFILES+=	17fea65e8c99.patch:-p1 # https://github.com/mortie/swaylock-effects/pull/38

COMMENT=	Screen locker for Wayland with fancy effects

MASTERDIR=	${.CURDIR}/../swaylock
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo

GH_ACCOUNT=	mortie
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support armv6, armv7 yet
USE_GCC=	yes
.endif

.include "${MASTERDIR}/Makefile"
