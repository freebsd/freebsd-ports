# New ports collection makefile for:	swm
# Date created:				2000-12-16
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	swm
PORTVERSION=	1.2.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.informatik.hu-berlin.de/~sperling/prog/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	trevor@FreeBSD.org

BINS=		swm #swmswitch
DOCDIR=		share/doc/${PORTNAME}
DOCS=		AUTHORS COMPILE_PARAMS COPYING ChangeLog LIESMICH README \
		README.iPaq TODO startswm swm.lsm
MAN1=		swm.1
PLIST=		${WRKDIR}/pkg-plist
SCRIPTS=	startswm.default
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

pre-install:
	${RM} -f ${PLIST}
	for i in ${BINS} ${SCRIPTS}; \
		do ${ECHO} bin/$${i} >> ${PLIST}; \
	done
	${ECHO} share/swm/background.jpg >> ${PLIST}
.if !defined(NOPORTDOCS)
	for i in ${DOCS}; \
		do ${ECHO} ${DOCDIR}/$${i} >> ${PLIST}; \
	done
	for i in 1 2 3; \
		do ${ECHO} ${DOCDIR}/examples/.swm/button$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm ${DOCDIR}/examples/.swm >> ${PLIST}
	${ECHO} @dirrm ${DOCDIR}/examples >> ${PLIST}
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
	${ECHO} @dirrm share/swm >> ${PLIST}
.endif

do-install:
	for i in ${BINS}; \
		do ${INSTALL_PROGRAM} ${WRKSRC}/$${i} ${PREFIX}/bin; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPTS} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/swm.1x ${PREFIX}/man/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/swm-de.1x \
		${PREFIX}/man/de_DE.ISO_8859-1/man1/swm.1x
	${MKDIR} ${PREFIX}/share/swm
	${INSTALL_DATA} ${WRKSRC}/share/swm/background.jpg \
		${PREFIX}/share/swm/background.jpg
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	cd ${WRKSRC} && \
		${CHMOD} -R 755 examples && \
		pax -r -w examples ${PREFIX}/${DOCDIR}
	for i in ${DOCS}; \
		do ${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR}; \
	done
.endif

.include <bsd.port.mk>
