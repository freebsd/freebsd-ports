# New ports collection makefile for:	tkgoodstuff
# Version required:	8.0-final
# Date created:		7 Oct 1996
# Whom:			pst
#
# $Id: Makefile,v 1.10 1998/02/21 22:38:06 fenner Exp $
#

DISTNAME=	tkgoodstuff8.0-final
PKGNAME=	tkgoodstuff-8.0
CATEGORIES=	x11 tk80
MASTER_SITES=	http://www-personal.umich.edu/~markcrim/tkgoodstuff/dists/

MAINTAINER=	pst@FreeBSD.org

RUN_DEPENDS=	fvwm2:${PORTSDIR}/x11/fvwm2
LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11-toolkits/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	TCLCONFIGSH=${PREFIX}/lib/tcl8.0/tclConfig.sh \
		TKCONFIGSH=${PREFIX}/lib/tk8.0/tkConfig.sh
CONFIGURE_ARGS=	--enable-libs
STRIP=

post-patch:
	@${RM} -f ${WRKSRC}/tcl/*.orig

.include <bsd.port.mk>
