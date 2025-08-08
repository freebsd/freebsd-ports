PORTNAME=	kanshi
DISTVERSIONPREFIX=	v
PORTVERSION=	1.7.0
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~emersion/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic display configuration for Wayland
WWW=		https://sr.ht/~emersion/kanshi/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libscfg.so:devel/libscfg \
		libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
MESON_ARGS=	-Dipc=disabled # https://github.com/varlink/libvarlink/issues/53
LDFLAGS+=	-lm # https://cgit.FreeBSD.org/ports/commit/?id=b991d37c58ed
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man5/${PORTNAME}.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/doc/${PORTNAME}.5.scd

.include <bsd.port.mk>
