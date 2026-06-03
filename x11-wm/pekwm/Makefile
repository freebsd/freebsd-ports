PORTNAME=	pekwm
DISTVERSION=	0.4.4
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://www.pekwm.se/pekwm/uv/

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Light, Unobtrusive, and configurable windowmanager
WWW=		https://www.pekwm.se/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png
RUN_DEPENDS=	gsed:textproc/gsed \
		xprop:x11/xprop

USES=		cmake compiler jpeg localbase pkgconfig xorg
USE_XORG=	ice sm x11 xext xft xinerama xpm xrandr

SUB_FILES=	pekwm.desktop

OPTIONS_DEFINE=		PANGO
OPTIONS_DEFAULT=	PANGO

PANGO_DESC=	Use Pango font support (both Cairo and Xft)

PANGO_USES=		gnome
PANGO_USE=		GNOME=cairo,pangoft2
PANGO_CMAKE_BOOL=	ENABLE_PANGO

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/pekwm.desktop \
		${STAGEDIR}${PREFIX}/share/xsessions/

.include <bsd.port.mk>
