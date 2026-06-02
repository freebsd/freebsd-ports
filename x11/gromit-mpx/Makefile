PORTNAME=	gromit-mpx
DISTVERSION=	1.9.0
CATEGORIES=	x11 wayland

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Desktop annotation tool, multi-pointer port of Gromit
WWW=		https://github.com/bk138/gromit-mpx

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libayatana-appindicator3.so:devel/libayatana-appindicator \
		libayatana-ido3-0.4.so:devel/ayatana-ido \
		libayatana-indicator3.so:devel/libayatana-indicator \
		libdbusmenu-glib.so:devel/libdbusmenu \
		liblz4.so:archivers/liblz4

USES=		cmake gettext gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	bk138
USE_GNOME=	gtk30
USE_XORG=	x11 xi

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e '/data.*cfg/s/)/ RENAME ${PORTNAME}.cfg.sample)/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
