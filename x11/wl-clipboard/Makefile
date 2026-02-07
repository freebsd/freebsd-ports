PORTNAME=	wl-clipboard
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Command-line copy/paste utilities for Wayland
WWW=		https://github.com/bugaevc/wl-clipboard

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	bugaevc
PLIST_FILES=	bin/wl-copy \
		bin/wl-paste \
		share/man/man1/wl-clipboard.1.gz \
		share/man/man1/wl-copy.1.gz \
		share/man/man1/wl-paste.1.gz \
		share/bash-completion/completions/wl-copy \
		share/bash-completion/completions/wl-paste \
		share/fish/vendor_completions.d/wl-copy.fish \
		share/fish/vendor_completions.d/wl-paste.fish \
		share/zsh/site-functions/_wl-copy \
		share/zsh/site-functions/_wl-paste

post-patch:
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/completions/fish/meson.build
# Search mime-support (etc/mime.types) and shared-mime-info (share/mime/types)
	@${REINPLACE_CMD} -e 's,/usr/share,${LOCALBASE}/share,' \
		-e '/local/!s,/etc,${LOCALBASE}&,' \
		${WRKSRC}/completions/bash/wl-copy \
		${WRKSRC}/completions/zsh/_wl-copy \
		${WRKSRC}/data/${PORTNAME}.1 \
		${WRKSRC}/src/util/files.c

.include <bsd.port.mk>
