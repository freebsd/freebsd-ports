DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0.0
PKGNAMESUFFIX=	-effects

COMMENT=	Screen locker for Wayland with fancy effects
WWW=		https://github.com/jirutka/swaylock-effects

MASTERDIR=	${.CURDIR}/../swaylock
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo

GH_ACCOUNT=	jirutka
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support armv6, armv7 yet
USE_GCC=	yes
.endif

.include "${MASTERDIR}/Makefile"
