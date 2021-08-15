# Created by: Ben Woods <woodsb02@FreeBSD.org>

PORTNAME=	slick-greeter
PORTVERSION=	1.5.4
CATEGORIES=	x11
PKGNAMEPREFIX=	lightdm-

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Slick-looking LightDM greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		liblightdm-gobject-1.so:x11/lightdm
RUN_DEPENDS=	numlockx>=0:x11/numlockx

USES=		autoreconf gettext gmake gnome pkgconfig python:run shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_PROJECT=	slick-greeter
USE_GNOME=	cairo dconf gdkpixbuf2 gtk30 intltool pygobject3
GLIB_SCHEMAS=	x.dm.slick-greeter.gschema.xml
USE_XORG=	pixman x11 xext
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-deinstall pkg-install
SHEBANG_FILES=	files/usr/bin/slick-greeter-check-hidpi \
		files/usr/bin/slick-greeter-set-keyboard-layout \
		makepot
bash_OLD_CMD=	/usr/bin/bash
bash_CMD=	/bin/sh

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr|"${PREFIX}|g' \
		${WRKSRC}/files/usr/bin/slick-greeter-set-keyboard-layout \
		${WRKSRC}/src/session-list.vala \
		${WRKSRC}/src/slick-greeter.vala \
		${WRKSRC}/src/user-list.vala
	@${MV} ${WRKSRC}/files/usr ${WRKSRC}/files/stage
	@${MKDIR} ${WRKSRC}/files/${PREFIX}
	@${MV} ${WRKSRC}/files/stage/* ${WRKSRC}/files/${PREFIX}/
	@${RMDIR} ${WRKSRC}/files/stage

post-install:
	${MV} ${STAGEDIR}${PREFIX}/share/xgreeters/slick-greeter.desktop \
		${STAGEDIR}${PREFIX}/share/xgreeters/lightdm-slick-greeter.desktop

.include <bsd.port.mk>
