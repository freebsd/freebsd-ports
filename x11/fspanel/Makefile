# New ports collection makefile for:	fspanel
# Date created:		17 jan 2001
# Whom:			The Anarcat <anarcat@anarcat.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	fspanel
PORTVERSION=	0.7.6
CATEGORIES=	x11
MASTER_SITES=	http://sapphire.sourceforge.net/

# patched version is from sapphire project (0.7.6)
# the original version (0.7) is there
#MASTER_SITES=	http://www.chatjunkies.org/${PORTNAME}/

MAINTAINER=	anarcat@anarcat.dyndns.org

USE_X_PREFIX=	yes
MAKEFILE=	Makefile.freebsd
ALL_TARGET=	${PORTNAME}

pre-patch:
	@${PERL} -pi.orig -e "s#/usr/local#${PREFIX}#g" ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
