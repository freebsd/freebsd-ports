# New ports collection makefile for:	ude
# Date created:		06 Mar 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	ude
PORTVERSION= 	0.2.7.1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://download.sourceforge.net/pub/sourceforge/udeproject/ \
		ftp://ude.the-coffeeshop.dk/pub/UDE/
DISTNAME=	${PORTNAME}-0.2.7-BETA

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.mk>
