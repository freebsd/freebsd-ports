# New ports collection makefile for:	swm
# Date created:				2000-12-16
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	swm
PORTVERSION=	1.2.5
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.informatik.hu-berlin.de/~sperling/prog/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	trevor@FreeBSD.org

BINS=		swm swmbg swmpanel swmswitch
DOCDIR=		share/doc/${PORTNAME}
DOCS=		AUTHORS COMPILE_PARAMS COPYING ChangeLog LIESMICH README \
		README.iPaq swm.lsm
EXAMPLES=	startswm.kde1 startswm.kde2
MAN1=		swm.1 swmbg.1
PLIST=		${WRKDIR}/pkg-plist
SCRIPTS=	startswm
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/src

pre-install:
	${RM} -f ${PLIST}
	for i in ${BINS} ${SCRIPTS}; \
		do ${ECHO_CMD} bin/$${i} >> ${PLIST}; \
	done
.if !defined(NOPORTDOCS)
	for i in ${DOCS}; \
		do ${ECHO_CMD} ${DOCDIR}/$${i} >> ${PLIST}; \
	done
	for i in 1 2 3; \
		do ${ECHO_CMD} ${DOCDIR}/examples/.swm/button$${i} >> ${PLIST}; \
	done
	for i in ${EXAMPLES}; \
		do ${ECHO_CMD} ${DOCDIR}/examples/$${i} >> ${PLIST}; \
	done
	${ECHO_CMD} @dirrm ${DOCDIR}/examples/.swm >> ${PLIST}
	${ECHO_CMD} @dirrm ${DOCDIR}/examples >> ${PLIST}
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	for i in ${BINS}; \
		do ${INSTALL_PROGRAM} ${WRKSRC}/$${i} ${PREFIX}/bin; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPTS} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/swm.1x ${PREFIX}/man/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/swmbg.1x ${PREFIX}/man/man1/swmbg.1
#	${INSTALL_MAN} ${WRKSRC}/swm-de.1x \
#		${PREFIX}/man/de_DE.ISO_8859-1/man1/swm.1x
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/../ && \
		${CHMOD} -R 755 examples && \
		pax -r -w examples ${PREFIX}/${DOCDIR}
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}/examples/
.endfor
	for i in ${DOCS}; \
		do ${INSTALL_DATA} ${WRKSRC}/../$${i} ${PREFIX}/${DOCDIR}; \
	done
.endif

.include <bsd.port.mk>
