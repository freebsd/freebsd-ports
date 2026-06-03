PORTNAME=	vdesk
PORTVERSION=	1.3
CATEGORIES=	x11
MASTER_SITES=	http://offog.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line utility for setting up and using virtual desktops
WWW=		https://offog.org/code/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vdesk
PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vdesk ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
