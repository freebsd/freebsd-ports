# $FreeBSD$

PORTNAME=	lavalauncher
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/commit/
PATCHFILES+=	7142822a8082.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple launcher panel for Wayland desktops

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome localbase meson pkgconfig
USE_GNOME=	cairo
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-page
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
