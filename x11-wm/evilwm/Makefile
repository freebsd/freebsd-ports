# New ports collection makefile for:	evilwm
# Date created:				2000-11-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		evilwm
PORTVERSION=		0.3.11
CATEGORIES=		x11-wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	trevor@FreeBSD.org

DOCDIR=		share/doc/${PORTNAME}
DOCS=		ChangeLog README README.multihead
MAN1=		evilwm.1
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${X11BASE}/include \
		-DMOUSE -DSTDIO -DSOLIDDRAG -DCOLOURMAP -DVWM \
		-L${X11BASE}/lib -o evilwm *.c -lX11

pre-install:
	${ECHO_CMD} bin/evilwm > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evilwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/evilwm.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
