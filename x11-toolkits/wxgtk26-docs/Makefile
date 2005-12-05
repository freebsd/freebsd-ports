# New ports collection makefile for:	wxgtk_doc_26
# Date created:				November, 15th 2005
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=	wxgtk_doc_26
PORTVERSION=	2.6.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxwindows
DISTNAME=	wxWidgets-${PORTVERSION}-HTML

MAINTAINER=	m.sund@arcor.de
COMMENT=	wxWidgets 2.6.2 HTML documentation

NO_BUILD=	YES

CONTRIBDOCDIR=	${WRKDIR}/wxWidgets-${PORTVERSION}/contrib/docs

WXGTKDOCDIR=	share/doc/${PORTNAME}
WRKSRC=		${WRKDIR}/wxWidgets-${PORTVERSION}/docs

do-install:
	@${MKDIR} ${PREFIX}/${WXGTKDOCDIR}
	@(cd ${WRKSRC} && ${FIND} html -type d -exec ${MKDIR} ${PREFIX}/${WXGTKDOCDIR}/{} \;)
	@(cd ${CONTRIBDOCDIR} && ${FIND} html -type d -exec ${MKDIR} ${PREFIX}/${WXGTKDOCDIR}/{} \;)
	@(cd ${WRKSRC} && ${FIND} html -type f -exec ${INSTALL_MAN} {} ${PREFIX}/${WXGTKDOCDIR}/{} \;)
	@(cd ${CONTRIBDOCDIR} && ${FIND} html -type f -exec ${INSTALL_MAN} {} ${PREFIX}/${WXGTKDOCDIR}/{} \;)

post-install:
	@(cd ${WRKSRC} && ${FIND} html -type f -exec ${ECHO} ${WXGTKDOCDIR}/{} >> ${TMPPLIST} \;)
	@(cd ${CONTRIBDOCDIR} && ${FIND} html -type f -exec ${ECHO} ${WXGTKDOCDIR}/{} >> ${TMPPLIST} \;)
	@(cd ${WRKSRC} && ${FIND} html/* -type d -exec ${ECHO} @dirrm ${WXGTKDOCDIR}/{} >> ${TMPPLIST} \;)
	@(cd ${CONTRIBDOCDIR} && ${FIND} html/* -type d -exec ${ECHO} @dirrm ${WXGTKDOCDIR}/{} >> ${TMPPLIST} \;)
	@${ECHO} @dirrm ${WXGTKDOCDIR}/html >> ${TMPPLIST}
	@${ECHO} @dirrm ${WXGTKDOCDIR} >> ${TMPPLIST}

.include <bsd.port.mk>
