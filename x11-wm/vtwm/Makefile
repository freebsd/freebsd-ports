PORTNAME=	vtwm
PORTVERSION=	5.5.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Twm with a virtual desktop and optional Motif-like features
WWW=		http://www.vtwm.org/

LICENSE=	MIT

LIB_DEPENDS=	libpng.so:graphics/png

USES=	pkgconfig xorg

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_XORG=	x11 xext xft xinerama xpm xmu xrandr

PLIST_FILES=	bin/vtwm \
		bin/nexpm \
		etc/system.vtwmrc \
		share/man/man1/vtwm.1.gz

OPTIONS_DEFINE=	SOUND
SOUND_DESC=	Sound support (via rplay)

SOUND_CONFIGURE_ENABLE=	sound
SOUND_LIB_DEPENDS=	librplay.so:audio/rplay

pre-patch:
	@${REINPLACE_CMD} -e 's|\$${datadir}/X11/vtwm|\$${prefix}/etc|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
