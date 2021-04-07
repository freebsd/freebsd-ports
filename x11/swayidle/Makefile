PORTNAME=	swayidle
DISTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	4cc31289ee81.patch:-p1 # https://github.com/swaywm/swayidle/pull/89
PATCHFILES+=	8862b3bad223.patch:-p1 # https://github.com/swaywm/swayidle/pull/89
PATCHFILES+=	88bc257f72f6.patch:-p1 # https://github.com/swaywm/swayidle/pull/89

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
