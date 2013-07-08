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
FETCH_ARGS=	-pRr
USE_GNOME=	gtk20 glib20 pango atk
USES=		iconv gmake
USE_XORG=	xmu
MAKE_ARGS=	"PREFIX=${PREFIX}"
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/sargon-${PORTNAME}-srg-${GITVERSION:S/^0-g//}

PORTDOCS=	README CREDITS CHANGELOG
MAN1=		trayer.1

PLIST_FILES=	bin/trayer

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
