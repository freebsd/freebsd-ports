# $FreeBSD$

PORTNAME=	swayidle
DISTVERSION=	1.2
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Idle management daemon for Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	swaywm
PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
