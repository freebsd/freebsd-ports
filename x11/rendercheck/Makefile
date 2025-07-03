PORTNAME=	rendercheck
DISTVERSION=	1.6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Small program for testing basic Render extension conformance
WWW=		https://gitlab.freedesktop.org/xorg/test/rendercheck

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:test,meson
USE_XORG=	x11 xext xorgproto xrender

PLIST_FILES=	bin/rendercheck share/man/man1/rendercheck.1.gz

.include <bsd.port.mk>
