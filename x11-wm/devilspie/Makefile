# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	devilspie
PORTVERSION=	0.22
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.burtonini.com/computing/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manipulation tool

OPTIONS_DEFINE=	DOCS

USE_GNOME=	libwnck
GNU_CONFIGURE=	yes
USES=		pkgconfig gettext gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

PORTDOCS=	AUTHORS NEWS README TODO
PLIST_FILES=	bin/devilspie \
		man/man1/devilspie.1.gz \
		share/locale/de/LC_MESSAGES/devilspie.mo

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
