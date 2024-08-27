PORTNAME=	salut
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	25
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sleek notification daemon

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo
USE_GITLAB=	yes
GL_ACCOUNT=	snakedye
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
