# New ports collection makefile for:   bbconf
# Date created:        29 October 2001
# Whom:                Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	bbconf
PORTVERSION=	1.8
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stijn@win.tue.nl

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_QT_VER=	3

MAN1=		bbconf.1

post-patch:
	@find ${WRKSRC} -name 'Makefile.in' -print | \
	    xargs ${PERL} -pi.orig -e 's#lib/bbconf#libexec/bbconf#g'

.include <bsd.port.mk>
