# New ports collection makefile for:	tkgoodstuff
# Version required:	4.2b1-8
# Date created:		7 Oct 1996
# Whom:			pst
#
# $Id: Makefile,v 1.7 1997/07/07 06:30:30 pst Exp $
#

DISTNAME=	tkgoodstuff4.2
PKGNAME=	tkgoodstuff-4.2b1.8
CATEGORIES=	x11
MASTER_SITES=	http://www-personal.umich.edu/~markcrim/tkgoodstuff/dists/

MAINTAINER=	pst@FreeBSD.org

RUN_DEPENDS=	fvwm2:${PORTSDIR}/x11/fvwm2
LIB_DEPENDS=	tk42\\.1:${PORTSDIR}/x11/tk42

WRKSRC=		${WRKDIR}/tkgoodstuff4.2b1-8
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	TCLCONFIGSH=${PREFIX}/lib/tcl7.6/tclConfig.sh \
		TKCONFIGSH=${PREFIX}/lib/tk4.2/tkConfig.sh
CONFIGURE_ARGS=	--enable-libs
STRIP=

post-patch:
	@${RM} -f ${WRKSRC}/tcl/*.orig

.include <bsd.port.mk>
