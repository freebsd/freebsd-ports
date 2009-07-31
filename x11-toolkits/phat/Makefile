# New ports collection makefile for:	phat
# Date created:		2007-03-06
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	phat
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	phat

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Collection of GTK+ widgets geared toward pro-audio apps

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libgnomecanvas gnomehack
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
