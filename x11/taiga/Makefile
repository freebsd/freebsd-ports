PORTNAME=	taiga
PORTVERSION=	s20200907
DISTVERSIONSUFFIX=	-34c64aa7c3d7
CATEGORIES=	x11 wayland
MASTER_SITES=	https://hg.sr.ht/~scoopta/${PORTNAME}/archive/${DISTVERSIONSUFFIX:S/^-//}${EXTRACT_SUFX}?dummy=/
DISTNAME=	${PORTNAME}${DISTVERSIONSUFFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Take animated screenshots on wlroots compositors

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libavcodec.so:multimedia/ffmpeg

USES=		compiler:c11 meson pkgconfig
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
