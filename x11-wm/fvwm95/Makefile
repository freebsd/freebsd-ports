# New ports collection makefile for:	fvwm95-2
# Version required:	2.0.43a
# Date created:		Sa   1 Feb 1997 14:46:05 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.6 1996/11/18 11:43:08 asami Exp $
#

DISTNAME=	fvwm95-2.0.43a-Autoconf
CATEGORIES=	x11
MASTER_SITES=	ftp://mitac11.uia.ac.be/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andreas@klemm.gtn.com

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=	${PREFIX}/lib/librplay.a:${PORTSDIR}/audio/rplay

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=/usr/X11R6 \
			--includedir=${PREFIX}/include \
			--libdir=${PREFIX}/lib

post-configure:
	@${ECHO} "See the sample.fvwm95rc file in the files directory"

.include <bsd.port.mk>
