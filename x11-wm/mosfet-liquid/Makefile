# New ports collection makefile for:	mosfet-liquid
# Date created:		August 22 2001
# Whom:			Michiel De Wilde <michiel.dewilde@rug.ac.be>
#
# $FreeBSD$
#

PORTNAME=	mosfet-liquid
PORTVERSION=	0.7
CATEGORIES=	x11-wm kde
MASTER_SITES=	http://www.mosfet.org/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	michiel.dewilde@rug.ac.be

BUILD_DEPENDS=	automake14:${PORTSDIR}/devel/automake14 \
		autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=2
INSTALLS_SHLIB=	yes

pre-configure:
	cd ${WRKSRC}; ${GMAKE} -f Makefile.cvs

.include <bsd.port.mk>
