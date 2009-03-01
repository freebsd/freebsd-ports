# New ports collection makefile for:	fluxter
# Date created:				18 Aug 2003
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	fluxter
PORTVERSION=	0.2.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.hydrus.org.uk/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop pager for the Fluxbox Slit

USE_XORG=	x11 ice xproto xt xaw xext
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/fluxbox|/${PORTNAME}|g" \
		${WRKSRC}/Makefile.in ${WRKSRC}/data/README.fluxter \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
