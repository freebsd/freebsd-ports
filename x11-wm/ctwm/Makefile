# New ports collection makefile for:	ctwm
# Date created:		13 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ctwm
PORTVERSION=	3.8a
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://ctwm.free.lp.se/dist/ \
		http://www.centralmiss.com/~matt/distfiles/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	An extension to twm, with support for multiple virtual screens, etc

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_IMAKE=	yes
USE_XORG=	xpm xmu
MAN1=		ctwm.1

.include <bsd.port.pre.mk>

# Very old versions need GNU m4
.if ( ${OSVERSION} < 500034 )
EXTRA_PATCHES+=	${FILESDIR}/gm4-patch
BUILD_DEPENDS+=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS+=	gm4:${PORTSDIR}/devel/m4
.endif

pre-configure:
	${CP} ${WRKSRC}/Imakefile.local-template ${WRKSRC}/Imakefile.local
	${CAT} ${FILESDIR}/Imakefile.local-additional >> ${WRKSRC}/Imakefile.local

.include <bsd.port.post.mk>
