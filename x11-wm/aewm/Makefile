# New ports collection makefile for:	aewm
# Date created:				2000-12-16
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	aewm
PORTVERSION=	1.1.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.red-bean.com/~decklin/aewm/

MAINTAINER=	trevor@FreeBSD.org

BINS=		aewm
DOCDIR=		share/doc/${PORTNAME}
DOCS=		Changelog README TODO
MAN1=		aewm.1
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_X_PREFIX=	yes

pre-install:
	${ECHO} bin/aewm > ${PLIST}
.if !defined(NOPORTDOCS)
	for i in ${DOCS}; \
		do ${ECHO} ${DOCDIR}/$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aewm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aewm.1x ${PREFIX}/man/man1/aewm.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	for i in ${DOCS}; \
		do ${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR}; \
	done
.endif

.include <bsd.port.mk>
