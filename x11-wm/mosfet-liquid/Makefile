# New ports collection makefile for:	mosfet-liquid
# Date created:		August 22 2001
# Whom:			Michiel De Wilde <michiel.dewilde@rug.ac.be>
#
# $FreeBSD$
#

PORTNAME=	mosfet-liquid
PORTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	x11-wm kde
MASTER_SITES=	http://www.mosfet.org/
DISTNAME=	${PORTNAME}${PORTVERSION}-pre4

MAINTAINER=	kde@freebsd.org
COMMENT=	A High Performance Liquid KDE style engine

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDEBASE_VER=3
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}pre4

pre-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile.cvs

.include <bsd.port.mk>
