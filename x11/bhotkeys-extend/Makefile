PORTNAME=	bhotkeys-extend
DISTVERSION=	1.7
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Super+E display-extend hotkey for bhotkeys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys-display-common>=1.2:x11/bhotkeys-display-common \
		bhotkeys:x11/bhotkeys \
		bosd:x11/bosd

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_ARCH=	yes

PLIST_FILES=	bin/display-extend \
		share/bhotkeys/plugins.d/extend \
		share/man/man1/display-extend.1.gz

.include <bsd.port.mk>
