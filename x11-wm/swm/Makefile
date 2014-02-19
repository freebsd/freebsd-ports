# Created by: trevor
# $FreeBSD$

PORTNAME=	swm
PORTVERSION=	1.3.4c
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.small-window-manager.de/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager for low-memory systems, with title bars and shading

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../doc/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S,c,,}/src

USE_XORG=	xpm
USES=		gmake
MAKEFILE=	Makefile-xpm
MAKE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="" CC="${CC}" XROOT="${LOCALBASE}"

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	* .swm
PLIST_FILES=	${BINS:S,^,bin/,} ${SCRIPTS:S,^,bin/,} \
		${DATA:S,^,%%DATADIR%%/pixmaps/,} \
		man/man1/swm.1.gz man/man1/swmbg.1.gz man/man1/swmswitch.1.gz \
		man/de/man1/swm.1.gz man/de/man1/swmbg.1.gz man/de/man1/swmswitch.1.gz
PLIST_DIRS=	%%DATADIR%%/pixmaps %%DATADIR%%
PLIST_DIRSTRY=	man/de/man1 man/de

BINS=		swm swmbg swmswitch
SCRIPTS=	startswm
DATA=		background.xpm closebox.xpm maxbox.xpm stickybox.xpm \
		swm.colors unstickybox.xpm

post-patch:
	@${REINPLACE_CMD} -e 's|monotype|fixed|g ; \
		 s|/usr/share/swm|${DATADIR}|g' ${WRKSRC}/swm.conf

post-build:
	cd ${WRKSRC}/../swmbg && ${CC} ${CFLAGS} -I${LOCALBASE}/include \
		*.c -o ${WRKSRC}/swmbg -lX11 -lXext -lXpm -L${LOCALBASE}/lib
	cd ${WRKSRC}/../swmswitch && ${CC} ${CFLAGS} -I${LOCALBASE}/include \
		*.c -o ${WRKSRC}/swmswitch -lX11 -L${LOCALBASE}/lib

do-install:
.for file in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
.for file in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/swm.1x ${STAGEDIR}${MANPREFIX}/man/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/../swmbg/swmbg.1x ${STAGEDIR}${MANPREFIX}/man/man1/swmbg.1
	${INSTALL_MAN} ${WRKSRC}/../swmswitch/swmswitch.1x ${STAGEDIR}${MANPREFIX}/man/man1/swmswitch.1
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/de/man1
	${INSTALL_MAN} ${WRKSRC}/swm-de.1x ${STAGEDIR}${MANPREFIX}/man/de/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/../swmbg/swmbg-de.1x ${STAGEDIR}${MANPREFIX}/man/de/man1/swmbg.1
	${INSTALL_MAN} ${WRKSRC}/../swmswitch/swmswitch-de.1x ${STAGEDIR}${MANPREFIX}/man/de/man1/swmswitch.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/../share/swm && ${COPYTREE_SHARE} pixmaps ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/../examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
