# New ports collection makefile for:	Xbae
# Date created:		11 December 96
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
# With some
# modifications from:	Andreas Klemm <andreas@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	xbae
PORTVERSION=	4.50.0
CATEGORIES=	x11-toolkits math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xbae
DISTNAME=	Xbae-${PORTVERSION}

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

USE_MOTIF=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=--enable-production

MAN3=		XbaeCaption.3 XbaeInput.3 XbaeMatrix.3

.include <bsd.port.mk>
