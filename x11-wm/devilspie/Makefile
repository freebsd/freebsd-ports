# New ports collection makefile for:	Devil's Pie
# Date created:			08 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		devilspie
PORTVERSION=		0.5.1
CATEGORIES=		x11-wm
MASTER_SITES=		http://www.burtonini.com/computing/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A window manipulation tool

USE_X_PREFIX=		yes
USE_GNOME=		libwnck libglade2
GNU_CONFIGURE=		yes

MAN1=			devilspie.1

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devilspie.dtd ${DATADIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-config.xml ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/NEWS \
		${WRKSRC}/README \
		${WRKSRC}/TODO \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
