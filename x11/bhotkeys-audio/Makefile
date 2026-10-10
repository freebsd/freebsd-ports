PORTNAME=	bhotkeys-audio
DISTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Volume and audio-output hotkeys for bhotkeys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys:x11/bhotkeys \
		bosd:x11/bosd \
		pactl:audio/pulseaudio

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
