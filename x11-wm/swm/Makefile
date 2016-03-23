# Created by: trevor
# $FreeBSD$

PORTNAME=	swm
PORTVERSION=	1.3.4c
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.small-window-manager.de/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager for low-memory systems, with title bars and shading

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S,c,,}
BUILD_WRKSRC=	${WRKSRC}/src

USE_XORG=	xpm
USES=		gmake
MAKEFILE=	Makefile-xpm
MAKE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="" CC="${CC}" XROOT="${LOCALBASE}"

PORTDOCS=	*
PORTEXAMPLES=	*

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|monotype|fixed|g ; \
		 s|/usr/share/swm|${DATADIR}|g' ${WRKSRC}/src/swm.conf

post-build:
	cd ${WRKSRC}/swmbg && ${CC} ${CFLAGS} -I${LOCALBASE}/include \
		*.c -o ${WRKSRC}/src/swmbg -lX11 -lXext -lXpm -L${LOCALBASE}/lib
	cd ${WRKSRC}/swmswitch && ${CC} ${CFLAGS} -I${LOCALBASE}/include \
		*.c -o ${WRKSRC}/src/swmswitch -lX11 -L${LOCALBASE}/lib

do-install:
.for f in swm swmbg swmswitch
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/src/startswm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/swm.1x ${STAGEDIR}${MANPREFIX}/man/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/swmbg/swmbg.1x ${STAGEDIR}${MANPREFIX}/man/man1/swmbg.1
	${INSTALL_MAN} ${WRKSRC}/swmswitch/swmswitch.1x ${STAGEDIR}${MANPREFIX}/man/man1/swmswitch.1
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/de/man1
	${INSTALL_MAN} ${WRKSRC}/src/swm-de.1x ${STAGEDIR}${MANPREFIX}/man/de/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/swmbg/swmbg-de.1x ${STAGEDIR}${MANPREFIX}/man/de/man1/swmbg.1
	${INSTALL_MAN} ${WRKSRC}/swmswitch/swmswitch-de.1x ${STAGEDIR}${MANPREFIX}/man/de/man1/swmswitch.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/share/swm && ${COPYTREE_SHARE} pixmaps ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	cd ${STAGEDIR}${EXAMPLESDIR} && ${MV} .swm dot.swm

.include <bsd.port.mk>
