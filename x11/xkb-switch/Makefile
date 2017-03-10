# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	xkb-switch
PORTVERSION=	1.4.0.20170217
CATEGORIES=	x11

MAINTAINER=	dg@syrec.org
COMMENT=	Switch your X keyboard layouts from the command line

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	ierton
GH_TAGNAME=	d623a6d

USES=		cmake
USE_XORG=	x11 xkbfile
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/xkb-switch \
		lib/libxkbswitch.so

PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
