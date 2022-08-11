PORTNAME=	swayidle
DISTVERSION=	1.7.1
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	28950f787813.patch:-p1 # https://github.com/swaywm/swayidle/pull/89
PATCHFILES+=	ff7569ad1129.patch:-p1 # https://github.com/swaywm/swayidle/pull/89
PATCHFILES+=	f2f7e4d0a7c8.patch:-p1 # https://github.com/swaywm/swayidle/pull/89
PATCHFILES+=	e81d40fca753.patch:-p1 # https://github.com/swaywm/swayidle/pull/115

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
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	BASU MANPAGES
OPTIONS_DEFAULT=BASU MANPAGES

BASU_DESC=		Login manager support via basu
BASU_LIB_DEPENDS=	libbasu.so:devel/basu
BASU_MESON_ENABLED=	logind

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-patch:
# Temporarily use ConsoleKit2 like sysutils/gnome-settings-daemon
	@${REINPLACE_CMD} -e 's,/login1,/ConsoleKit/Manager,' \
		-e 's,login1,ConsoleKit,' \
		${WRKSRC}/main.c

.include <bsd.port.mk>
