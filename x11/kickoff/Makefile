PORTNAME=	kickoff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	23
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalistic program launcher for Wayland
WWW=		https://github.com/j0ru/kickoff

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	j0ru
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
