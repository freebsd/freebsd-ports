# New ports collection makefile for:	buttonbox
# Date created:				2000-12-17
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	buttonbox
PORTVERSION=	0.03
CATEGORIES=	x11
MASTER_SITES=	http://www.sto-kerrig.org/free-software/projects/button-box/
DISTNAME=	${PORTNAME:S/b/B/g}-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org

DOCDIR=		share/doc/${PORTNAME}
DOCS=		COPYING ChangeLog DEDICATION README TODO
PLIST=		${WRKDIR}/pkg-plist

USE_X_PREFIX=	yes

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o buttonbox -L${X11BASE}/lib \
		-I${X11BASE}/include -lX11 -lXext button.c configuration.c \
		colour.c dispatcher.c main.c

pre-install:
	${ECHO} bin/buttonbox > ${PLIST}
	${ECHO} lib/X11/app-defaults/ButtonBox.ad >> ${PLIST}
.if !defined(NOPORTDOCS)
	for i in ${DOCS}; \
		do ${ECHO} ${DOCDIR}/$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/ButtonBox.ad ${X11BASE}/lib/X11/app-defaults/
	${INSTALL_PROGRAM} ${WRKSRC}/buttonbox ${X11BASE}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	for i in ${DOCS}; \
		do ${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR}; \
	done
.endif

.include <bsd.port.mk>
