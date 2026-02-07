PORTNAME=	tinywm
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://incise.org/files/dev/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ridiculously tiny window manager
WWW=		http://incise.org/tinywm.html

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg tar:tgz
USE_XORG=	x11

PLIST_FILES=	bin/tinywm
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|CC)|CC) ${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinywm ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
