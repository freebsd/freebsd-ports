PORTNAME=	slick-greeter
DISTVERSION=	2.2.5
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Slick-looking LightDM greeter
WWW=		https://github.com/linuxmint/slick-greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		liblightdm-gobject-1.so:x11/lightdm

RUN_DEPENDS=	numlockx:x11/numlockx \
		xinput:x11/xinput \
		setxkbmap:x11/setxkbmap \
		ubuntu-font>0:x11-fonts/ubuntu-font \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme

USES=		gettext-tools gnome localbase meson pkgconfig python:run \
		shebangfix vala:build xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 pygobject3

USE_XORG=	pixman x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_FILES=	files/usr/bin/slick-greeter-check-hidpi \
		files/usr/bin/slick-greeter-set-keyboard-layout \
		files/usr/bin/slick-greeter-enable-tap-to-click \
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

.include <bsd.port.mk>
