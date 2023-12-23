PORTNAME=	gromit-mpx
DISTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Desktop annotation tool, multi-pointer port of Gromit
WWW=		https://github.com/bk138/gromit-mpx

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libappindicator3.so:devel/libappindicator

USES=		cmake gettext gnome pkgconfig xorg
USE_CSTD=	gnu99
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11 xi
GH_ACCOUNT=	bk138
LDFLAGS+=	-Wl,--as-needed # atk, dbusmenu, pango

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e '/data.*cfg/s/)/ RENAME ${PORTNAME}.cfg.sample)/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
