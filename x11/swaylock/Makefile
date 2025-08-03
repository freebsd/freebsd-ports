PORTNAME=	swaylock
DISTVERSIONPREFIX?=	v
DISTVERSION?=	1.8.3
PORTREVISION?=	0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT?=	Screen locker for Wayland
WWW?=		https://github.com/swaywm/swaylock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.25:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

CONFLICTS_INSTALL=	${PORTNAME}-*

USES=		compiler:c11 cpe gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT?=	swaywm
CPE_VENDOR=	swaywm
USE_GNOME=	cairo pango
PLIST_FILES=	bin/${PORTNAME} \
		etc/pam.d/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	MANPAGES PIXBUF
OPTIONS_DEFAULT=MANPAGES PIXBUF

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

PIXBUF_USE=		GNOME=gdkpixbuf
PIXBUF_MESON_ENABLED=	gdk-pixbuf

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e "s/meson.project_version()/'${DISTVERSIONFULL}'/" \
		${WRKSRC}/meson.build
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=275328
	@${REINPLACE_CMD} -e 's/_POSIX_C_SOURCE=200809L/_XOPEN_SOURCE=700/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
