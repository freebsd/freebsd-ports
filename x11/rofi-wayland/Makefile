DISTVERSION=	1.6.1
DISTVERSIONSUFFIX=	${PKGNAMESUFFIX}
PORTREVISION=	0
PKGNAMESUFFIX=	-wayland

MASTERDIR=	${.CURDIR}/../rofi
DISTINFO_FILE=	${.CURDIR}/distinfo

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

GH_ACCOUNT=	lbonn

CONFLICTS_INSTALL=	${PORTNAME}

.include "${MASTERDIR}/Makefile"
