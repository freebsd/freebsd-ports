# New ports collection makefile for:	BMPanel 2
# Date created:				17 May 2012
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpanel2
DISTVERSION=	2.1pre1
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice, lightweight NETWM compliant panel for X

LICENSE=	MIT

USE_CMAKE=	yes
USE_GNOME=	pango
USE_XORG=	x11 xext

LDFLAGS+=	-L${LOCALBASE}/lib		# XXX should not be needed

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' ${WRKSRC}/xdg.c
	@${REINPLACE_CMD} -e '/^#include/s,alloca,stdlib,' \
		${WRKSRC}/widget-utils.c
	@${REINPLACE_CMD} -e 's,uint,unsigned,' ${WRKSRC}/args.c
# Disable unused optional features (and thus unbreak "make clean")
	@${REINPLACE_CMD} -e '/^OPTION/s, ON, OFF,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
