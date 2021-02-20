# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	xkb-switch
PORTVERSION=	1.8.5
CATEGORIES=	x11

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Switch your X keyboard layouts from the command line

LICENSE=	GPLv3

USES=		cmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ierton
USE_XORG=	x11 xkbfile
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DMAN_COMPRESSION="gz" -DMANDIR="${MANPREFIX}/man"

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/xkb-switch \
		lib/libxkbswitch.so \
		lib/libxkbswitch.so.1 \
		lib/libxkbswitch.so.1.8.5 \
		man/man1/xkb-switch.1.gz

PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
