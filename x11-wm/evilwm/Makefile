# New ports collection makefile for:	evilwm
# Date created:				2000-11-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	evilwm
PORTVERSION=	1.0.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	lasg@lasg.dk
COMMENT=	Minimalist window manager based on 9wm

USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		evilwm.1
PORTDOCS=	ChangeLog README TODO
PLIST_FILES=	bin/evilwm

CFLAGS+=	-DSOLIDDRAG -DINFOBANNER -DVWM -DSHAPE -DMOUSE -DSNAP \
		-DSTDIO -DCOLOURMAP -DVERSION=\\\"${PORTVERSION}\\\" \
		-I${X11BASE}/include
LDFLAGS=	-L${X11BASE}/lib -lX11 -lXext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
