# $FreeBSD$

PORTNAME=	libxcvt
PORTVERSION=	s20210325
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Calculate VESA CVT mode lines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	xorg-server # bin/cvt

USES=		meson
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	ofourdan
GL_COMMIT=	81747a3d1270edb4d9df8f133206914512f604fe

.include <bsd.port.mk>
