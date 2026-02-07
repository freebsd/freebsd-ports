PORTNAME=	kanshi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	x11 wayland
MASTER_SITES=	https://gitlab.freedesktop.org/emersion/${PORTNAME}/-/releases/${DISTVERSIONFULL}/downloads/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Dynamic display configuration for Wayland
WWW=		https://gitlab.freedesktop.org/emersion/kanshi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libscfg.so:devel/libscfg \
		libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig

MESON_ARGS=	-Dipc=disabled # https://github.com/varlink/libvarlink/issues/53

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man5/${PORTNAME}.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}&|' \
		${WRKSRC}/doc/${PORTNAME}.5.scd

.include <bsd.port.mk>
