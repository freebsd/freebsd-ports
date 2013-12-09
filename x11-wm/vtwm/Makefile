# Created by: Bruce A. Mah <bmah@ca.sandia.gov>
# $FreeBSD$

PORTNAME=	vtwm
PORTVERSION=	5.4.99.20130906
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	ak-various-projects

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Twm with a virtual desktop and optional Motif-like features

LICENSE=	MIT

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

USE_XZ=	yes

USES=	pkgconfig

GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xft xinerama xpm xmu xrandr

WRKSRC=	${WRKDIR}/vtwm-20130906

PLIST_FILES=	bin/vtwm \
		bin/nexpm \
		etc/system.vtwmrc \
		man/man1/vtwm.1.gz

OPTIONS_DEFINE=	SOUND
SOUND_DESC=	Sound support (via rplay)

SOUND_CONFIGURE_ENABLE=	sound
SOUND_LIB_DEPENDS=	librplay.so:${PORTSDIR}/audio/rplay

pre-patch:
	@${REINPLACE_CMD} -e 's|\$${datadir}/X11/vtwm|\$${prefix}/etc|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
