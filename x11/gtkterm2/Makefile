# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	gtkterm2
PORTVERSION=	0.2.3
PORTREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	SF/gtkterm/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK-2 terminal with tabs

USE_GNOME=	vte
USES=		pkgconfig gmake
USE_AUTOTOOLS=	libtool

PORTDOCS=	README
PLIST_FILES=	bin/gtkterm2 \
		share/locale/de/LC_MESSAGES/gtkterm2.mo \
		%%DATADIR%%/pixmaps/gtkterm2.png
PLIST_DIRS=	%%DATADIR%%/pixmaps %%DATADIR%%

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=""||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkterm2 ${STAGEDIR}${PREFIX}/bin/gtkterm2
	${INSTALL_DATA} ${WRKSRC}/po/de.gmo \
		${STAGEDIR}${PREFIX}/share/locale/de/LC_MESSAGES/gtkterm2.mo
	@${MKDIR} ${STAGEDIR}${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/gtkterm2.png \
		${STAGEDIR}${DATADIR}/pixmaps/gtkterm2.png
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
