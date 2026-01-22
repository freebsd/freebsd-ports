PORTNAME=	weltschmerz
DISTVERSION=	1.10.0
CATEGORIES=	x11
MASTER_SITES=	https://git.oriole.systems/weltschmerz/snapshot/

MAINTAINER=	juhani@krekela.fi
COMMENT=	Terminal emulator in Vala
WWW=		https://oriole.systems/posts/weltschmerz

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gettext gnome pkgconfig vala:build xorg
USE_GNOME=	gtk30 vte3
USE_XORG=	x11

PORTSCOUT=	site:https://git.oriole.systems/weltschmerz/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/weltschmerz

.include <bsd.port.mk>
