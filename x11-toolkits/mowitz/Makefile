# New ports collection makefile for:	Mowitz
# Date created:		this 7th day of January, 2002
# Whom:			mi
#
# $FreeBSD$

PORTNAME=	Mowitz
PORTVERSION=	0.1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://siag.nu/pub/mowitz/

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XLIB=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-Dcfree=free"

post-install:
	${RM} ${PREFIX}/lib/libMowitz.la

.include <bsd.port.mk>
