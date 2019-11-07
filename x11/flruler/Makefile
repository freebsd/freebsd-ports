# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flruler
PORTVERSION=	1.05
CATEGORIES=	x11
MASTER_SITES=	http://seriss.com/people/erco/fltk/flruler/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	On-screen pixel ruler

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libfltk.a:x11-toolkits/fltk

USES=		gmake perl5 xorg
USE_PERL5=	build
USE_XORG=	x11 xcursor xext xfixes xft xinerama

PLIST_FILES=	bin/flruler man/man1/flruler.1.gz \
		share/icons/hicolor/128x128/apps/flruler.png
PORTDOCS=	*

DESKTOP_ENTRIES=	"Flruler" "${COMMENT}" "${PORTNAME}.png" \
			"${PORTNAME}" "Utility;" false

OPTIONS_DEFINE=	DOCS

post-patch:
# New windows won't get created with zero width and height for some reason
	@${REINPLACE_CMD} -e 's/,0,0/,1,1/' ${WRKSRC}/flruler.C

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/misc/flruler-icon.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES.txt TODO.txt \
		docs/${PORTNAME}.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
