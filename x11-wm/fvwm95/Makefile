# New ports collection makefile for:	fvwm95-2
# Date created:		Sa   1 Feb 1997 14:46:05 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	fvwm95
PORTVERSION=	2.0.43a
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=   http://ftp.yars.free.net/pub/software/unix/platforms/linux/x/fvwm95/ \
		http://ftp.cc.ntut.edu.tw/ftp/Xwindow/xfree86/Linux/wm/fvwm-95/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Autoconf
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/librplay.a:${PORTSDIR}/audio/rplay
RUN_DEPENDS=	${X11BASE}/icons/chuck.xpm:${PORTSDIR}/x11/fbsd-icons

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib

MAN1=		fvwm95.1

post-install:
		@${INSTALL_MAN}	$(WRKSRC)/fvwm/fvwm95.man \
			$(PREFIX)/man/man1/fvwm95.1

.include <bsd.port.mk>
