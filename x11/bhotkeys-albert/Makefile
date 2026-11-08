PORTNAME=	bhotkeys-albert
DISTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Super+Space Albert launcher plugin for bhotkeys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	albert:x11/albert \
		bhotkeys:x11/bhotkeys

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/albert-super-space \
		share/bhotkeys/plugins.d/albert \
		share/man/man1/albert-super-space.1.gz

.include <bsd.port.mk>
