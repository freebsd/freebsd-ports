# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmpanel2
DISTVERSION=	2.1pre1
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice, lightweight NETWM compliant panel for X11

LICENSE=	MIT

USES=		cmake pkgconfig
USE_GNOME=	pango
USE_XORG=	x11 xext

LDFLAGS+=	-L${LOCALBASE}/lib		# XXX should not be needed

OPTIONS_DEFINE=	TEMPERATURE
TEMPERATURE_DESC=	Build with temperature widget (for CPU, etc.)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEMPERATURE}
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	danfe
PATCHFILES=	${PORTNAME}-temperature-widget.diff
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' ${WRKSRC}/xdg.c
	@${REINPLACE_CMD} -e '/^#include/s,alloca,stdlib,' \
		${WRKSRC}/widget-utils.c
	@${REINPLACE_CMD} -e 's,uint,unsigned,' ${WRKSRC}/args.c
# Disable unused optional features (and thus unbreak "make clean")
	@${REINPLACE_CMD} -e '/^OPTION/s, ON, OFF,' ${WRKSRC}/CMakeLists.txt
	@${RM} -f ${WRKSRC}/themes/striped/theme.orig

.include <bsd.port.mk>
