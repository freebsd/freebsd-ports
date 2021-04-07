PORTNAME=	wl-clipboard
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	x11 wayland

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Command-line copy/paste utilities for Wayland

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	bugaevc

PLIST_FILES=	bin/wl-copy \
		bin/wl-paste \
		man/man1/wl-clipboard.1.gz \
		man/man1/wl-copy.1.gz \
		man/man1/wl-paste.1.gz \
		share/bash-completion/completions/wl-copy \
		share/bash-completion/completions/wl-paste \
		share/zsh/site-functions/_wl-copy \
		share/zsh/site-functions/_wl-paste

.include <bsd.port.mk>
