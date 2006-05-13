# New ports collection makefile for:	wxgtk_doc
# Date created:				1 Apr 23:51:14 2003 CEST
# Whom:					Michal Pasternak <dotz@irc.pl>
#
# $FreeBSD$
#

PORTNAME=	wxgtk_doc
PORTVERSION=	2.4.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxwindows
DISTNAME=	wxWindows-${PORTVERSION}-HTML

MAINTAINER=	ports@FreeBSD.org
COMMENT=	wxWindows documentation in HTML

LATEST_LINK=	wxgtk24_doc

NO_BUILD=	YES
USE_ZIP=	YES

WXGTKDOCDIR=	${PREFIX}/share/doc/${PORTNAME}/html/
WRKSRC=		${WRKDIR}/wxWindows-${PORTVERSION}/docs/html/

post-patch:
	@${REINPLACE_CMD} -e 's|../pdf/wxTutorial.pdf|http://users.skynet.be/saw/download/wxWindows/wxTutorial.pdf|' ${WRKSRC}/index.htm

do-install:
	@${MKDIR} ${WXGTKDOCDIR}
	@${CP} -R ${WRKSRC}/* ${WXGTKDOCDIR}

post-install:
	@(cd ${WRKSRC} && ${FIND} * -type f | ${XARGS} printf "share/doc/${PORTNAME}/html/%s\n" >> ${TMPPLIST})
	@(cd ${WRKSRC} && ${FIND} * -type d | ${XARGS} printf "@dirrm share/doc/${PORTNAME}/html/%s\n" >> ${TMPPLIST})
	@${ECHO} @dirrm share/doc/${PORTNAME}/html >> ${TMPPLIST}
	@${ECHO} @dirrm share/doc/${PORTNAME} >> ${TMPPLIST}

.include <bsd.port.mk>
