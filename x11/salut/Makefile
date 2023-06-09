PORTNAME=	salut
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Sleek notification daemon

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo
USE_GITLAB=	yes
GL_ACCOUNT=	snakedye
GL_COMMIT=	bb53391bac0c379dffdddb3cb35b423a8738a962
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
