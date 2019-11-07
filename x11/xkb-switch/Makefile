# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	xkb-switch
PORTVERSION=	1.6.0
CATEGORIES=	x11

# https://github.com/ierton/xkb-switch/pull/41
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	2075a8cdd5456c906fcd49278c1003dcb6b9f880.patch:-p1

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
		lib/libxkbswitch.so.1.6.0 \
		man/man1/xkb-switch.1.gz

PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
