# New ports collection makefile for:	XView
# Version required:	3.2p1-X11R6
# Date created:		22 November 1994
# Whom:			ljo (orig)
#
# $FreeBSD$
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-3.2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}	\
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	libraries

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
IMAKEINCLUDE=	"-I${X11BASE}/lib/X11/config -I${WRKSRC}/config"
MAKE_ENV+=	IMAKEINCLUDE=${IMAKEINCLUDE}
XMKMF=		${SETENV} IMAKEINCLUDE=${IMAKEINCLUDE} xmkmf -a
ALL_TARGET=	World

MAN1=		msgfmt.1 xgettext.1 xview.1

post-install:
.if !defined(NOPORTDOCS)
	@(cd $(WRKSRC); $(MAKE) -k 'SUBDIRS=doc' install)
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
