# New ports collection makefile for:	fluxter
# Date created:				18 Aug 2003
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	fluxter
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://benedict.isomedia.com/homes/stevencooper/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop pager for the Fluxbox Slit

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/fluxbox|/${PORTNAME}|g" \
		${WRKSRC}/Makefile.in ${WRKSRC}/data/README.fluxter \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
