# New ports collection makefile for:	Mowitz
# Date created:		this 7th day of January, 2002
# Whom:			mi
#
# $FreeBSD$

PORTNAME=	Mowitz
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://siag.nu/pub/mowitz/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	This is the Mowitz ("More widgets") library

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_AUTOTOOLS=	libtool:22
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xawm=Xaw3d

post-install:
	${RM} ${PREFIX}/lib/libMowitz.la
# Anyone knows a better way?

.include <bsd.port.mk>
