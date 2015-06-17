# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	wmfs
DISTVERSION=	201104
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://wmfs.info/attachments/download/45/ \
		http://cloud.github.com/downloads/xorg62/wmfs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Floating and tiling Window Manager From Scratch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USES=		pkgconfig
USE_XORG=	x11 xft xpm
HAS_CONFIGURE=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	XRANDR XINERAMA IMLIB
OPTIONS_DEFAULT=	XRANDR XINERAMA IMLIB

CONFIGURE_ARGS=	--prefix ${PREFIX} \
		--man-prefix ${MANPREFIX}/man \
		--xdg-config-dir ${PREFIX}/etc/xdg

XRANDR_USE=	XORG=xrandr
XRANDR_CONFIGURE_WITH+=	xrandr
XINERAMA_USE=	XORG=xinerama
XINERARAM_CONFIGURE_WITH=	xinerama
IMLIB_LIB_DEPENDS=	libImlib2.so:${PORTSDIR}/graphics/imlib2
IMLIB_CONFIGURE_WITH=	imlib2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
