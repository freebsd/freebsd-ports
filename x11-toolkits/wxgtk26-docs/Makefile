# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	wxgtk_doc
PORTVERSION=	2.6.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/wxwindows/Documents/${PORTVERSION}
DISTNAME=	wxWidgets-${PORTVERSION}-HTML

MAINTAINER=	m.sund@arcor.de
COMMENT=	wxWidgets ${PORTVERSION} HTML documentation

LATEST_LINK=	wxgtk26_doc

NO_BUILD=	YES

WXGTKDOCDIR=	share/doc/${PORTNAME}_26
WRKSRC=		${WRKDIR}/wxWidgets-${PORTVERSION}/docs

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/${WXGTKDOCDIR}
	@(cd ${WRKSRC} && ${FIND} html -type d -exec ${MKDIR} ${PREFIX}/${WXGTKDOCDIR}/{} \;)
	@(cd ${WRKSRC} && ${FIND} html -type f -exec ${INSTALL_MAN} {} ${PREFIX}/${WXGTKDOCDIR}/{} \;)

post-install:
	@(cd ${WRKSRC} && ${FIND} html -type f -exec ${ECHO} ${WXGTKDOCDIR}/{} >> ${TMPPLIST} \;)
	@(cd ${WRKSRC} && ${FIND} html/* -type d -exec ${ECHO} @dirrm ${WXGTKDOCDIR}/{} >> ${TMPPLIST} \;)
	@${ECHO} @dirrm ${WXGTKDOCDIR}/html >> ${TMPPLIST}
	@${ECHO} @dirrm ${WXGTKDOCDIR} >> ${TMPPLIST}

.include <bsd.port.mk>
