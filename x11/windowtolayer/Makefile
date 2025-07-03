PORTNAME=	windowtolayer
DISTVERSIONPREFIX=	v
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Any Wayland window as wallpaper
WWW=		https://gitlab.freedesktop.org/mstoeckl/windowtolayer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo python:build
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mstoeckl
BINARY_ALIAS=	python3=${PYTHON_CMD}
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
