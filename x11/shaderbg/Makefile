PORTNAME=	shaderbg
DISTVERSION=	s20230316
DISTVERSIONSUFFIX=	-0-g027d4f8
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~mstoeckl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Render shaders as a live wallpaper on Wayland
WWW=		https://sr.ht/~mstoeckl/shaderbg/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

USES=		compiler:c11 gl meson pkgconfig
USE_GL=		egl
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
