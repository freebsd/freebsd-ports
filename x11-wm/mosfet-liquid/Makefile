# New ports collection makefile for:	mosfet-liquid
# Date created:		August 22 2001
# Whom:			Michiel De Wilde <michiel.dewilde@rug.ac.be>
#
# $FreeBSD$
#

PORTNAME=	mosfet-liquid
PORTVERSION=	0.9.5
CATEGORIES=	x11-wm kde
#mosfet.org is up but not working ...
#if mosfet doesn't come to his senses, this may be
#the end of the line for this port.
#MASTER_SITES=	http://www.mosfet.org/ \
MASTER_SITES=	http://people.FreeBSD.org/~alane/mosfet/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@geeksrus.net

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDEBASE_VER=3
INSTALLS_SHLIB=	yes

BROKEN=		"This port is scheduled for termination"

pre-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile.cvs

.include <bsd.port.mk>
