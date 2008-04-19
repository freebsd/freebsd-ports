# ex:ts=8
# New ports collection makefile for:	ahwm
# Date created:			2003-01-22
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	ahwm
PORTVERSION=	0.90
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://people.cs.uchicago.edu/~ahiorean/ahwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 window manager

USE_XORG=	x11 xext

GNU_CONFIGURE=	yes
MAKE_ARGS=	prefix=${PREFIX} exec_prefix=${PREFIX}

MAN5=		ahwmrc.5
MLINKS=		ahwmrc.5 ahwm.5
PLIST_FILES=	bin/ahwm

post-patch:
	@${REINPLACE_CMD} -e 's,@prefix@@,@,g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
