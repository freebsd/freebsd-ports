# New ports collection makefile for:	evilwm
# Date created:				2000-11-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		evilwm
PORTVERSION=		0.2.7
CATEGORIES=		x11-wm
# not in MASTER_SITE_SOURCEFORGE
MASTER_SITES=		ftp://projects.sourceforge.net/pub/evilwm/

MAINTAINER=		trevor@FreeBSD.org

DOCDIR=			share/doc/${PORTNAME}
DOCS=			Changes.kja3 README
.if !defined(NOPORTDOCS)
MAN1=			evilwm.1
.endif
PLIST=			${WRKDIR}/pkg-plist
USE_GMAKE=		yes
USE_X_PREFIX=		yes

pre-install:
	${ECHO} bin/evilwm > ${PLIST}
.if !defined(NOPORTDOCS)
	for i in ${DOCS}; \
		do ${ECHO} ${DOCDIR}/$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	for i in ${DOCS}; \
		do ${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR}; \
	done
	${GZIP_CMD} -c ${WRKSRC}/evilwm.man > ${WRKSRC}/evilwm.1.gz
	${INSTALL_MAN} ${WRKSRC}/evilwm.1.gz ${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
