# New ports collection makefile for:   enlightenment
# Version required:    0.13
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.10 1997/11/29 01:32:04 asami Exp $
#

DISTNAME=	enl_BETA-0.13
PKGNAME=	enlightenment-0.13
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.mandrake.net/pub/enlightenment/ \
		http://www.rasterman.com/ftp/
DISTFILES=	enl_BETA-0.13.src.tar.gz \
		enl-0.13-themes.tar.gz

MAINTAINER=	vanilla@MinJe.com.TW

LIB_DEPENDS=	Im\\.4\\.:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/enl-0.13

post-install:
	${MKDIR} ${X11BASE}/lib/X11/enlightenment/themes
	${INSTALL_DATA} ${WRKDIR}/enl-0.13-themes/DEFAULT ${X11BASE}/lib/X11/enlightenment/themes
	${INSTALL_DATA} ${WRKDIR}/enl-0.13-themes/DEFAULT_small ${X11BASE}/lib/X11/enlightenment/themes

.include <bsd.port.mk>
