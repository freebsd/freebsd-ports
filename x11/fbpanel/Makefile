# New ports collection makefile for:	fbpanel
# Date created:		Sat Jun 26 13:43:50 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	fbpanel
PORTVERSION=	4.12
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@fsck.ch
COMMENT=	Desktop panel that includes a taskbar, pager, launchbar and more

USE_GNOME=	gtk20
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_GMAKE=	yes

MAN1=		fbpanel.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/man/Makefile

.include <bsd.port.mk>
