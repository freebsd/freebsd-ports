# New ports collection makefile for:   enlightenment
# Version required:    0.14
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.20 1998/08/06 15:32:15 vanilla Exp $
#

DISTNAME=	enlightenment-0.14
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
		ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

BUILD_DEPENDS=  ${LOCALBASE}/lib/perl5/site_perl/5.005/i386-freebsd/Gtk.pm:${PORTSDIR}/x11/p5-Gtk

LIB_DEPENDS=	esd\\.0\\.0:${PORTSDIR}/audio/esound \
		Fnlib\\.0\\.3:${PORTSDIR}/graphics/fnlib \
		Imlib\\.1\\.7:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS=-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/e

.include <bsd.port.mk>
