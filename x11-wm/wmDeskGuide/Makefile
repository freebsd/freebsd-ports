# New ports collection makefile for:		wmDeskGuide
# Date created:					26 July 2002
# Whom:						Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	wmDeskGuide
PORTVERSION=	0.2
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://charybda.icm.edu.pl/~jarwyp/data/own/wmDeskGuide/build/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pager for the WindowMaker dock

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomelibs gdkpixbuf
USE_REINPLACE=	yes
USE_GMAKE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/wmDeskGuide

post-patch:
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|G_GNUC_PRETTY_FUNCTION |G_GNUC_PRETTY_FUNCTION, |g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmDeskGuide ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
