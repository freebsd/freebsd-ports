# New ports collection makefile for:	tkgoodstuff
# Date created:		7 Oct 1996
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	tkgoodstuff
PORTVERSION=	8.0
PORTREVISION=	1
CATEGORIES=	x11 tk80
#
# No longer published by original developer.  This port still works, although
# there are other (better) applications that do similar things.  For now,
# use the local FreeBSD.ORG port cache.
#
#MASTER_SITES=	http://www-personal.umich.edu/~markcrim/tkgoodstuff/dists/
DISTNAME=	${PORTNAME}${PORTVERSION}-final

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TkGoodstuff module for fvwm2 window manager - requires XPM and fvwm2

RUN_DEPENDS=	fvwm2:${PORTSDIR}/x11-wm/fvwm2
LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	TCLCONFIGSH=${PREFIX}/lib/tcl8.0/tclConfig.sh \
		TKCONFIGSH=${PREFIX}/lib/tk8.0/tkConfig.sh
CONFIGURE_ARGS=	--enable-libs
STRIP=

post-patch:
	@${RM} -f ${WRKSRC}/tcl/*.orig

.include <bsd.port.mk>
