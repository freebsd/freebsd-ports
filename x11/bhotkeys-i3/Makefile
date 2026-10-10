PORTNAME=	bhotkeys-i3
DISTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Chords for the i3 window manager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys:x11/bhotkeys

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	share/bhotkeys/plugins.d/i3-mic-mute \
		share/bhotkeys/plugins.d/i3-mute \
		share/bhotkeys/plugins.d/i3-vol-down \
		share/bhotkeys/plugins.d/i3-vol-up

.include <bsd.port.mk>
