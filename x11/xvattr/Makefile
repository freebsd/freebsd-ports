# ex:ts=8
# Ports collection makefile for:	xvattr
# Date created:			Jan 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xvattr
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" INCDIRS="-I${X11BASE}/include" \
		LIBDIRS="-L${X11BASE}/lib"
ALL_TARGET=	${PORTNAME}

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
IGNORE=		"Require Xv Extension"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
