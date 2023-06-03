PORTNAME=	gromit-mpx
DISTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	698a43a8dcd7.patch:-p1 # https://github.com/bk138/gromit-mpx/pull/177
PATCHFILES+=	7cd913191b48.patch:-p1 # https://github.com/bk138/gromit-mpx/pull/177

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Desktop annotation tool, multi-pointer port of Gromit
WWW=		https://github.com/bk138/gromit-mpx

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libappindicator3.so:devel/libappindicator

USES=		cmake gnome pkgconfig
USE_CSTD=	gnu99
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30
GH_ACCOUNT=	bk138
LDFLAGS+=	-Wl,--as-needed # atk, dbusmenu, pango

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USES=	xorg
X11_USE=	XORG=x11 xi

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e '/data.*cfg/s/)/ RENAME ${PORTNAME}.cfg.sample)/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
