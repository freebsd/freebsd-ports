# New ports collection makefile for:	boxtools
# Date created:		September 11, 2002
# Whom:			Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	boxtools
PORTVERSION=	0.65.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blackboxwm
DISTNAME=	blackbox-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Style tools for the blackbox family of window managers

MAN1=		bsetbg.1 bsetroot.1

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

pre-patch:
	${REINPLACE_CMD} -e 's#PACKAGE=blackbox#PACKAGE=boxtools#' \
		-e 's#-pedantic##' ${WRKSRC}/configure

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/util/bsetbg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/bsetroot ${PREFIX}/bin
	cd ${WRKSRC}/nls && ${MAKE} install
	${INSTALL_MAN} ${WRKSRC}/doc/bsetbg.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bsetroot.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
