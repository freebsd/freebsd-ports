# New ports collection makefile for:	yawm
# Date created:				2002-03-10
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	yawm
PORTVERSION=	0.0.1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.sai.msu.su/pub/X11/win_man/
DISTNAME=	yawm-0.0.1-a4

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Has title bars, iconizing, maximizing, taskbar, placement, clock

GNU_CONFIGURE=	yes
PLIST=		${WRKDIR}/pkg-plist
#USE_GMAKE=	yes
USE_X_PREFIX=	yes
DOCS=		AUTHORS COPYING ChangeLog

pre-install:
	${ECHO_CMD} bin/yawm > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} share/doc/yawm/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/yawm >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/yawm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
