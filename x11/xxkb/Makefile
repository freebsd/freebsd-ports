# New ports collection makefile for:	xxkb
# Date created:		5 Mar 2001
# Whom:			Alexander Matey <matey@cis.ohio-state.edu>
#
# $FreeBSD$
#

PORTNAME=	xxkb
PORTVERSION=	1.10
CATEGORIES=	russian ukrainian
MASTER_SITES=	http://www.tsu.ru/~pascal/other/xxkb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@matey.org
COMMENT=	An XKB keyboard layout switcher and indicator

MAN1=		xxkb.1
USE_XPM=	yes
USE_IMAKE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/XXkb.ad ${PREFIX}/lib/X11/app-defaults/XXkb
	@${MKDIR} ${PREFIX}/share/xxkb
	${INSTALL_DATA} ${WRKSRC}/*.xpm ${PREFIX}/share/xxkb
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xxkb
.for FILE in LICENSE CHANGES.koi8 README.koi8
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/doc/xxkb
.endfor
.endif

.include <bsd.port.mk>
