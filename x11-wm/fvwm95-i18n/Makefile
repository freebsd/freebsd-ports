# New ports collection makefile for:	fvwm95-2
# Version required:	2.0.43a
# Date created:		Sa   1 Feb 1997 14:46:05 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.10 1997/06/09 19:16:35 andreas Exp $
#

DISTNAME=	fvwm95-2.0.43a-Autoconf
PKGNAME=	fvwm95-2.0.43a
CATEGORIES=	x11
MASTER_SITES=	ftp://mitac11.uia.ac.be/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andreas@klemm.gtn.com

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=	/usr/local/lib/librplay.a:${PORTSDIR}/audio/rplay

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--includedir=/usr/local/include \
		--libdir=/usr/local/lib

MAN1=		fvwm95.1

post-install:
		@${INSTALL_MAN}	$(WRKSRC)/fvwm/fvwm95.man \
				$(PREFIX)/man/man1/fvwm95.1
		(cd ${PREFIX}/icons; tar xzf ${FILESDIR}/fbsd-icons.tar.gz)

.include <bsd.port.mk>
