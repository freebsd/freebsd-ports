# New ports collection makefile for:	fvwm95-2
# Version required:	2.0.43a
# Date created:		Sa   1 Feb 1997 14:46:05 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.18 1998/08/05 09:31:43 asami Exp $
#

DISTNAME=	fvwm95-2.0.43a-Autoconf
PKGNAME=	fvwm95-2.0.43a
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://mitac11.uia.ac.be/pub/fvwm95/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=	${LOCALBASE}/lib/librplay.a:${PORTSDIR}/audio/rplay
RUN_DEPENDS=	${X11BASE}/icons/chuck.xpm:${PORTSDIR}/x11/fbsd-icons

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib

MAN1=		fvwm95.1

post-install:
		@${INSTALL_MAN}	$(WRKSRC)/fvwm/fvwm95.man \
			$(PREFIX)/man/man1/fvwm95.1

.include <bsd.port.mk>
