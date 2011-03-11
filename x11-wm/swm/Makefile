# New ports collection makefile for:	swm
# Date created:				2000-12-16
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	swm
PORTVERSION=	1.3.4
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://www2.informatik.hu-berlin.de/~sperling/prog/
EXTRACT_SUFX=	c-src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager for low-memory systems, with title bars and shading

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BINS=		swm swmbg swmswitch
DOCDIR=		share/doc/${PORTNAME}
MAN1=		swm.1 swmbg.1
MAKEFILE=	Makefile-xpm
PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	share/swm/pixmaps share/swm
SCRIPTS=	startswm
USE_GMAKE=	yes
USE_XORG=	x11 xext xpm
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

post-patch:
.for ii in init.c swm.conf
	${MV} ${WRKSRC}/${ii} ${WRKSRC}/${ii}.orig
	${SED} -e "s:PREFIX:${PREFIX}:g" \
		< ${WRKSRC}/${ii}.orig > ${WRKSRC}/${ii}
.endfor

post-build:
	cd ${WRKSRC}/../swmbg && ${CC} ${CFLAGS} -I${LOCALBASE}/include *.c \
		-o ${WRKSRC}/swmbg -lX11 -lXext -lXpm -L${LOCALBASE}/lib
	cd ${WRKSRC}/../swmswitch && ${CC} ${CFLAGS} -I${LOCALBASE}/include *.c \
	-o ${WRKSRC}/swmswitch -lX11 -L${LOCALBASE}/lib

pre-install:
	${RM} -f ${PLIST}
	for i in ${BINS} ${SCRIPTS}; \
		do ${ECHO_CMD} bin/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/../share/swm/pixmaps && \
		${FIND} -s . -type f | ${CUT} -c3-999 | \
		${SED} -e 's:^:share/swm/pixmaps/:' >> ${PLIST}
.if !defined(NOPORTDOCS)
	for i in ${DOCS}; \
		do ${ECHO_CMD} ${DOCDIR}/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/../doc && ${FIND} -s . -type f | cut -c3-999 \
		| ${SED} -e 's:^:${DOCDIR}/:' >> ${PLIST}
	cd ${WRKSRC}/../ && ${FIND} -s examples -type f \
		| ${SED} -e 's:^examples:share/examples/swm:' >> ${PLIST}
	cd ${WRKSRC}/../ && ${FIND} -d examples -type d | \
		${SED} -e 's:^examples:@dirrm share/examples/swm:' >> ${PLIST}
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	for i in ${BINS}; \
		do ${INSTALL_PROGRAM} ${WRKSRC}/$${i} ${PREFIX}/bin; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPTS} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/swm.1x ${PREFIX}/man/man1/swm.1
	${INSTALL_MAN} ${WRKSRC}/../swmbg/swmbg.1x ${PREFIX}/man/man1/swmbg.1
#	${INSTALL_MAN} ${WRKSRC}/swm-de.1x \
#		${PREFIX}/man/de_DE.ISO_8859-1/man1/swm.1x
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/../ && ${CHMOD} -R 755 doc examples
	cd ${WRKSRC}/../doc && ${PAX} -r -w * ${DOCSDIR}
	cd ${WRKSRC}/../examples && ${PAX} -r -w * .swm ${EXAMPLESDIR}
.endif
	${MKDIR} ${DATADIR}/pixmaps
	cd ${WRKSRC}/../share/swm/pixmaps && ${PAX} -r -w * ${DATADIR}/pixmaps

.include <bsd.port.mk>
