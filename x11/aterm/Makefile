# New ports collection makefile for:   aterm
# Version required:	0.3.5
# Date created:		17 January 1999
# Whom:			Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.3 1999/03/08 20:59:19 steve Exp $
#

DISTNAME=	aterm-0.3.5
CATEGORIES=	x11
MASTER_SITES=	http://members.xoom.com/sashav/aterm/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-background-image \
		--disable-delete-key --disable-backspace-key \
		--enable-fading --enable-utmp --enable-wtmp

MAN1=		aterm.1

.include <bsd.port.mk>
