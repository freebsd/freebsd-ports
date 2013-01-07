# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	wmfs
DISTVERSION=	201104
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://wmfs.info/attachments/download/45/ \
		http://cloud.github.com/downloads/xorg62/wmfs/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A floating and tiling Window Manager From Scratch

LICENSE=	BSD

LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

USE_PKGCONFIG=	build
USE_XORG=	x11 xft xpm
HAS_CONFIGURE=	yes

MAN1=	${PORTNAME}.1
MANCOMPRESSED=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	XRANDR XINERAMA IMLIB
OPTIONS_DEFAULT=	XRANDR XINERAMA IMLIB

.include <bsd.port.options.mk>

CONFIGURE_ARGS=	--prefix ${PREFIX} \
			--man-prefix ${MANPREFIX}/man \
			--xdg-config-dir ${PREFIX}/etc/xdg

.if ${PORT_OPTIONS:MXRANDR}
USE_XORG+=	xrandr
.else
CONFIGURE_ARGS+=	--without-xrandr
.endif

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
.else
CONFIGURE_ARGS+=	--without-xinerama
.endif

.if ${PORT_OPTIONS:MIMLIB}
USE_EFL+=	imlib2
.else
CONFIGURE_ARGS+=	--without-imlib2
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
