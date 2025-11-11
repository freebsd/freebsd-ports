PORTNAME=	salut
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	28
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sleek notification daemon

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Fails to build with rust 1.90.0
EXPIRATION_DATE=2025-11-24

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo
USE_GITLAB=	yes
GL_ACCOUNT=	snakedye
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
