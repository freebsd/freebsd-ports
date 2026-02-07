PORTNAME=	xtset
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.lemis.com/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to set title on an xterm

# LICENSE=	NONE

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/xtset share/man/man1/xtset.1.gz
MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtset ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtset.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
