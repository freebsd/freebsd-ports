# New ports collection makefile for:	XView
# Date created:		22 November 1994
# Whom:			ljo (orig)
#
# $FreeBSD$
#

PORTNAME=	xview
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}	\
		${MASTER_SITE_XCONTRIB}
# former for ${MASER_SITE_LOCAL}, latter for ${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS libraries
DISTNAME=	xview3.2p1-X11R6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Window-System-based Visual/Integrated Environment for Workstations

USE_IMAKE=	yes
INSTALLS_SHLIB=	yes
IMAKEINCLUDE=	"-I${X11BASE}/lib/X11/config -I${WRKSRC}/config"
MAKE_ENV+=	IMAKEINCLUDE=${IMAKEINCLUDE}
XMKMF=		${SETENV} IMAKEINCLUDE=${IMAKEINCLUDE} xmkmf -a
ALL_TARGET=	World
USE_REINPLACE=	yes
REINPLACE_ARGS=     -i ""

MAN1=		msgfmt.1 xgettext.1 xview.1

post-configure:
	${CP} ${FILESDIR}/wait.h.in ${WRKSRC}/build/include/wait.h
	${CP} ${FILESDIR}/types.h.in ${WRKSRC}/build/include/types.h

post-install:

	${INSTALL_DATA} ${WRKSRC}/build/include/wait.h ${X11BASE}/include/xview/
	${INSTALL_DATA} ${WRKSRC}/build/include/types.h ${X11BASE}/include/xview/
.if !defined(NOPORTDOCS)
	@(cd $(WRKSRC); $(MAKE) -k 'SUBDIRS=doc' install)
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's|#include <sys/types.h>|#include "types.h"|;\
	s|^#endif.*$$|#endif|;s|^#else.*$$|#else|'
.endif

.include <bsd.port.post.mk>
