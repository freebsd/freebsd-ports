# $FreeBSD$

PORTNAME=	wayland-logout
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	6e0c13c8b198.patch:-p1 # https://github.com/soreau/wayland-logout/pull/6
PATCHFILES+=	64eb1c3c9a4d.patch:-p1 # https://github.com/soreau/wayland-logout/pull/6

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple logout on Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	soreau
MESON_ARGS=	${${OPSYS} == FreeBSD && ${OSREL:R} >= 13:?-Dimplementation=c:}
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
