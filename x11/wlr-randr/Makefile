PORTNAME=	wlr-randr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xrandr clone for wlroots compositors
WWW=		https://sr.ht/~emersion/wlr-randr/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
