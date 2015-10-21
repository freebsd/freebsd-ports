# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmpanel2
DISTVERSION=	2.1pre1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE
PATCH_SITES=	LOCAL/danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight NetWM-compliant panel (taskbar) for X11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pkgconfig
USE_GNOME=	pango
USE_XORG=	x11 xext

OPTIONS_DEFINE=	OPACITY TEMPERATURE
OPACITY_DESC=		Opacity setting with compositing window managers
TEMPERATURE_DESC=	Build with temperature widget (for CPU, etc.)

OPACITY_PATCHFILES=	${PORTNAME}-opacity-setting.diff
TEMPERATURE_PATCHFILES=	${PORTNAME}-temperature-widget.diff

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' ${WRKSRC}/xdg.c
	@${REINPLACE_CMD} -e '/^#include/s,alloca,stdlib,' \
		${WRKSRC}/widget-utils.c
	@${REINPLACE_CMD} -e 's,uint,unsigned,' ${WRKSRC}/args.c
# Disable unused optional features (and thus unbreak "make clean")
	@${REINPLACE_CMD} -e '/^OPTION/s, ON, OFF,' ${WRKSRC}/CMakeLists.txt
	@${RM} -f ${WRKSRC}/themes/striped/theme.orig

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bmpanel2

.include <bsd.port.mk>
