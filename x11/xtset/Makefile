PORTNAME=	xtset
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	http://www.lemis.com/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to set title on an xterm

# LICENSE=	NONE

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/xtset man/man1/xtset.1.gz
MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
