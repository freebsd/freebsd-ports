PORTNAME=	kanshi
DISTVERSIONPREFIX=	v
PORTVERSION=	1.2.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Dynamic display configuration for Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
			man/man5/${PORTNAME}.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/${PORTNAME}.5.scd

.include <bsd.port.mk>
