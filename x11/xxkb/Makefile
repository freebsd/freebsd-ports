# New ports collection makefile for:	xxkb
# Date created:		5 Mar 2001
# Whom:			Alexander Matey <matey@cis.ohio-state.edu>
#
# $FreeBSD$
#

PORTNAME=		xxkb
PORTVERSION=		1.11
CATEGORIES=		x11
MASTER_SITES=		SF
DISTNAME=		${PORTNAME}-${PORTVERSION}-src

MAINTAINER=		alexander.pohoyda@gmx.net
COMMENT=		An XKB keyboard layout switcher and indicator

WRKSRC=			${WRKDIR}/${PORTNAME}
USE_XORG=		xpm
USE_IMAKE=		yes

MAN1=			xxkb.1

OPTIONS=		LIBRSVG	"With SVG(librsvg2) support" off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBRSVG)
LIB_DEPENDS+=		rsvg-2.2:${PORTSDIR}/graphics/librsvg2
XMKMF=			xmkmf -a -DWITH_SVG_SUPPORT
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for file in LICENSE README CHANGES.koi8 README.koi8
	    ${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.post.mk>
