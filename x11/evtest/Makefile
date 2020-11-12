# $FreeBSD$

PORTNAME=	evtest
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.34
CATEGORIES=	x11
MASTER_SITES=	https://gitlab.freedesktop.org/libevdev/${PORTNAME}/-/archive/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Input device event monitor and query tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev

USES=		autoreconf localbase
GNU_CONFIGURE=	yes

CFLAGS+=	-DPACKAGE_VERSION=${PKGVERSION}

PLIST_FILES=	bin/evtest

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
MANPAGES_PLIST_FILES=	man/man1/evtest.1.gz

.include <bsd.port.mk>
