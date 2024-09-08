PORTNAME=	windowtolayer
PORTVERSION=	s20240320
PORTREVISION=	3
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Any Wayland window as wallpaper
WWW=		https://gitlab.freedesktop.org/mstoeckl/windowtolayer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mstoeckl
GL_TAGNAME=	a5b89c3
PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
