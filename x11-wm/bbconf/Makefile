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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configurator for the Blackbox window manager

USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=13
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_QT_VER=	3

MAN1=		bbconf.1

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' -print | \
	    ${XARGS} ${PERL} -pi.orig -e 's#lib/bbconf#libexec/bbconf#g'

.include <bsd.port.mk>
