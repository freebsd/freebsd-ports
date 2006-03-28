# New ports collection makefile for:	evilwm
# Date created:				2000-11-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	evilwm
PORTVERSION=	0.99.24
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalist window manager based on 9wm

USE_X_PREFIX=	yes
USE_GCC=	3.4+

MAN1=		evilwm.1
PLIST_FILES=	bin/evilwm
PORTDOCS=	ChangeLog README TODO

CFLAGS+=	-I${X11BASE}/include

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d' ${WRKSRC}/${MAKEFILE}

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
