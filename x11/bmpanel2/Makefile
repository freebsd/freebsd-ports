PORTNAME=	bmpanel2
DISTVERSION=	2.1pre1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/bmpanel2/
PATCH_SITES=	LOCAL/danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight NetWM-compliant panel (taskbar) for X11
WWW=		https://code.google.com/archive/p/bmpanel2/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc

USES=		cmake gnome pkgconfig xorg
USE_GNOME=	cairo pango
USE_XORG=	x11 xext
CMAKE_OFF=	BMPANEL2_FEATURE_CONFIG

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

.include <bsd.port.mk>
