PORTNAME=	slick-greeter
PORTVERSION=	2.0.2
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Slick-looking LightDM greeter
WWW=		https://github.com/linuxmint/slick-greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		liblightdm-gobject-1.so:x11/lightdm \
		libxapp.so:x11/xapp

RUN_DEPENDS=	numlockx>=0:x11/numlockx

USES=		autoreconf gettext gmake gnome localbase pkgconfig python:run shebangfix \
		vala:build xorg
USE_GNOME=	cairo dconf gdkpixbuf2 gtk30 intltool pygobject3

USE_XORG=	pixman x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

GNU_CONFIGURE=	yes
SHEBANG_FILES=	files/usr/bin/slick-greeter-check-hidpi \
		files/usr/bin/slick-greeter-set-keyboard-layout \
		makepot
bash_OLD_CMD=	/usr/bin/bash
bash_CMD=	/bin/sh
SUB_FILES=	pkg-deinstall pkg-install

GLIB_SCHEMAS=	x.dm.slick-greeter.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr|"${PREFIX}|g' \
		-e 's|"/etc|"${PREFIX}/etc|g' \
		${WRKSRC}/files/usr/bin/slick-greeter-set-keyboard-layout \
		${WRKSRC}/src/session-list.vala \
		${WRKSRC}/src/settings.vala \
		${WRKSRC}/src/slick-greeter.vala \
		${WRKSRC}/src/user-list.vala
	@${RM} ${WRKSRC}/files/usr/bin/slick-greeter-set-keyboard-layout.bak
	@${MKDIR} ${WRKSRC}/files/${PREFIX}
	@${MV} ${WRKSRC}/files/usr/bin ${WRKSRC}/files/${PREFIX}/bin
	@${MV} ${WRKSRC}/files/usr/share ${WRKSRC}/files/${PREFIX}/share

.include <bsd.port.mk>
