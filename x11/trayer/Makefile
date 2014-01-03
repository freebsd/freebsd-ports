# Created by: Alexey Mikhailov <karma@ez.pereslavl.ru>
# $FreeBSD$

PORTNAME=	trayer
PORTVERSION=	1.1.5
CATEGORIES=	x11
MASTER_SITES=	http://github.com/sargon/${PORTNAME}-srg/tarball/${PORTNAME}-${PORTVERSION}/
DISTNAME=	sargon-${PORTNAME}-srg-${PORTNAME}-${PORTVERSION}-${GITVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Lightweight GTK2-based systray for UNIX desktop

GITVERSION=	0-g5353f80
USE_GNOME=	gtk20 glib20 pango atk
USES=		iconv gmake pkgconfig
USE_XORG=	xmu
MAKE_ARGS=	"PREFIX=${PREFIX}"
WRKSRC=		${WRKDIR}/sargon-${PORTNAME}-srg-${GITVERSION:S/^0-g//}

PORTDOCS=	README CREDITS CHANGELOG

PLIST_FILES=	bin/trayer man/man1/trayer.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|$$(PREFIX)/|$$(DESTDIR)&|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
