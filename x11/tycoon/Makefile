# New ports collection makefile for:	tycoon
# Date created:		19 September 1997
# Whom:			steve@farrell.org
#
# $FreeBSD$
#

PORTNAME=	tycoon
PORTVERSION=	1.07o
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A nifty set of desktop apps, including floating buttons

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

USE_IMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

post-patch:
	${RM} -f ${WRKSRC}/xbackdrop/backdrops/index~
	${REINPLACE_CMD} -e 's,/usr/lib,${PREFIX}/lib,' \
		${WRKSRC}/xbackdrop/backdrops/index
	${FIND} ${WRKSRC} -name '*.c' -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's,FL_REVISION>=80,FL_REVISION >= 80 || FL_VERSION != 0,g'

.include <bsd.port.mk>
