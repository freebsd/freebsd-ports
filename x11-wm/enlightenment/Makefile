# New ports collection makefile for:   enlightenment
# Version required:    0.13.3
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.12 1998/02/01 02:03:44 vanilla Exp $
#

DISTNAME=	enl_BETA-0.13.3
PKGNAME=	enlightenment-0.13.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/
DISTFILES=	enl_BETA-0.13.3.tar.gz \
		enl-0.13-themes.tar.gz

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	Imlib\\.1\\.:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/enl-0.13.3

post-install:
	${MKDIR} ${X11BASE}/lib/X11/enlightenment/themes
	${INSTALL_DATA} ${WRKDIR}/enl-0.13-themes/DEFAULT ${X11BASE}/lib/X11/enlightenment/themes
	${INSTALL_DATA} ${WRKDIR}/enl-0.13-themes/DEFAULT_small ${X11BASE}/lib/X11/enlightenment/themes

.include <bsd.port.mk>
