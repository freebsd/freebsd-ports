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

MANLANG=	"" de
MAN1=		swm.1 swmbg.1 swmswitch.1
PORTDOCS=	*
PORTEXAMPLES=	* .swm
PLIST_FILES=	${BINS:S,^,bin/,} ${SCRIPTS:S,^,bin/,} \
		${DATA:S,^,%%DATADIR%%/pixmaps/,}
PLIST_DIRS=	%%DATADIR%%/pixmaps %%DATADIR%%
PLIST_DIRSTRY=	man/de/man1 man/de

BINS=		swm swmbg swmswitch
SCRIPTS=	startswm
DATA=		background.xpm closebox.xpm maxbox.xpm stickybox.xpm \
		swm.colors unstickybox.xpm

NO_STAGE=	yes
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
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/swm.1x ${MANPREFIX}/man/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/../swmbg/swmbg.1x ${MANPREFIX}/man/man1/swmbg.1
	${INSTALL_MAN} ${WRKSRC}/../swmswitch/swmswitch.1x ${MANPREFIX}/man/man1/swmswitch.1
	@${MKDIR} ${MANPREFIX}/man/de/man1
	${INSTALL_MAN} ${WRKSRC}/swm-de.1x ${MANPREFIX}/man/de/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/../swmbg/swmbg-de.1x ${MANPREFIX}/man/de/man1/swmbg.1
	${INSTALL_MAN} ${WRKSRC}/../swmswitch/swmswitch-de.1x ${MANPREFIX}/man/de/man1/swmswitch.1
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/../share/swm && ${COPYTREE_SHARE} pixmaps ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/../examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
