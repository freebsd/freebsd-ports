PORTNAME=	cwm
DISTVERSION=	6.7
CATEGORIES=	x11-wm
MASTER_SITES=	https://leahneukirchen.org/releases/

MAINTAINER=	me@emilengler.com
COMMENT=	Minimalistic window manager for X11 based on evilwm

LICENSE=	ISCL

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		pkgconfig xorg
USE_XORG=	x11 xft xrandr
MAKE_ARGS=	MANPREFIX="${MANPREFIX}/man"
PLIST_FILES=	bin/cwm \
		man/man1/cwm.1.gz \
		man/man5/cwmrc.5.gz

post-patch:
	@${REINPLACE_CMD} 's@/usr/X11R6@${LOCALBASE}@' ${WRKSRC}/cwmrc.5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cwm

.include <bsd.port.mk>
