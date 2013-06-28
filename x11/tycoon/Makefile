# Created by: steve@farrell.org
# $FreeBSD$

PORTNAME=	tycoon
PORTVERSION=	1.07o
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nifty set of desktop apps, including floating buttons

LIB_DEPENDS=	forms.2:${PORTSDIR}/x11-toolkits/xforms

USES=		imake
USE_XORG=	xaw
REINPLACE_ARGS=	-i ""

post-patch:
	${RM} -f ${WRKSRC}/xbackdrop/backdrops/index~
	${REINPLACE_CMD} -e 's,/usr/lib,${PREFIX}/lib,' \
		${WRKSRC}/xbackdrop/backdrops/index
	${FIND} ${WRKSRC} -name '*.c' -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's,FL_REVISION>=80,FL_REVISION >= 80 || FL_VERSION != 0,g'

.include <bsd.port.mk>
