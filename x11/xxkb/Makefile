# New ports collection makefile for:	xxkb
# Date created:		5 Mar 2001
# Whom:			Alexander Matey <matey@cis.ohio-state.edu>
#
# $FreeBSD$
#

PORTNAME=	xxkb
PORTVERSION=	1.10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xxkb

MAINTAINER=	alexander.pohoyda@gmx.net
COMMENT=	An XKB keyboard layout switcher and indicator

MAN1=		xxkb.1
USE_XPM=	yes
USE_IMAKE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/XXkb.ad ${PREFIX}/lib/X11/app-defaults/XXkb
	@${MKDIR} ${PREFIX}/share/xxkb
	${INSTALL_DATA} ${WRKSRC}/*.xpm ${PREFIX}/share/xxkb
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in LICENSE CHANGES.koi8 README.koi8
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
