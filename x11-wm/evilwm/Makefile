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
USE_X_PREFIX=		yes

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${X11BASE}/include -L${X11BASE}/lib -o evilwm *.c -lX11

pre-install:
	${ECHO} bin/evilwm > ${PLIST}
.if !defined(NOPORTDOCS)
	for i in ${DOCS}; \
		do ${ECHO} ${DOCDIR}/$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evilwm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	for i in ${DOCS}; \
		do ${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR}; \
	done
	${INSTALL_MAN} ${WRKSRC}/evilwm.man ${PREFIX}/man/man1/evilwm.1
.endif

.include <bsd.port.mk>
