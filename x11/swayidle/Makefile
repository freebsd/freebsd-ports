PORTNAME=	swayidle
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Idle management daemon for Wayland
WWW=		https://github.com/swaywm/swayidle

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.40:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dlogind=disabled
PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
