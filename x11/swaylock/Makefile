PORTNAME=	swaylock
DISTVERSION?=	1.6
PORTREVISION?=	1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT?=	Screen locker for Wayland

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
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_MESON_ENABLED=	gdk-pixbuf

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build
# Respect LOCALBASE for unix-selfauth-helper
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/pam/${PORTNAME}

.include <bsd.port.mk>
