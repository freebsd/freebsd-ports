# New ports collection makefile for:   aterm
# Version required:	0.3.4
# Date created:		17 January 1999
# Whom:			Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.2 1999/02/03 10:33:43 asami Exp $
#

DISTNAME=	aterm-0.3.4
CATEGORIES=	x11
MASTER_SITES=	http://members.xoom.com/sashav/aterm/ \
		http://www.tigr.net/afterstep/as-apps/download/aterm/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-background-image \
		--disable-delete-key --disable-backspace-key
MAN1=		aterm.1

.include <bsd.port.mk>
