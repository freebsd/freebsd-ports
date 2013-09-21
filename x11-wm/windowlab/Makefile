# Created by: Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
# $FreeBSD$

PORTNAME=	windowlab
PORTVERSION=	1.40
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	repacked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small window manager for X11

LICENSE=	GPLv2

OPTIONS_DEFINE=	XFT DOCS

USE_XORG=	x11 xext
USE_GMAKE=	yes
MAKE_ENV=	XROOT="${LOCALBASE}" SYSCONFDIR="${ETCDIR}"

MAN1=		windowlab.1x
PORTDOCS=	CHANGELOG README
PLIST_FILES=	bin/windowlab %%ETCDIR%%/menurc
PLIST_DIRS=	%%ETCDIR%%

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
USES+=		pkgconfig
MAKE_ENV+=	EXTRA_INC="$$(pkg-config --cflags xft)" \
		EXTRA_LIBS="$$(pkg-config --libs xft)"
CFLAGS+=	-DXFT
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(PREFIX\) =|\1 ?=| ; \
		 s|^\(XROOT\) =|\1 ?=| ; \
		 s|^\(SYSCONFDIR\) =|\1 ?=| ; \
		 s|^\(CC\) =|\1 ?=|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} windowlab ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} windowlab.1x ${MANPREFIX}/man/man1)
	@${MKDIR} ${ETCDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} windowlab.menurc ${ETCDIR}/menurc)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
