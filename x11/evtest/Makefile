PORTNAME=	evtest
DISTVERSION=	1.35
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Input device event monitor and query tool
WWW=		https://gitlab.freedesktop.org/libevdev/evtest

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev

USES=		autoreconf localbase
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org/
GL_ACCOUNT=	libevdev
GL_TAGNAME=	da347a8f88d2e5729dd12d61ee9743f902065b55

CFLAGS+=	-DPACKAGE_VERSION=${PKGVERSION}

PLIST_FILES=	bin/evtest

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
MANPAGES_PLIST_FILES=	share/man/man1/evtest.1.gz

.include <bsd.port.mk>
