# New ports collection makefile for:	mrxvt
# Date created:				27 Nov 2004
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	mrxvt
PORTVERSION=	0.4.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	materm

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A tabbed version of rxvt

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		mrxvt.1

.include <bsd.port.mk>
