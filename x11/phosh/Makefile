# $FreeBSD$

PORTNAME=	phosh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Pure Wayland shell prototype for mobile devices

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
LIB_DEPENDS=	libfeedback-0.0.so:accessibility/feedbackd \
		libpulse-mainloop-glib.so:audio/pulseaudio \
		libwayland-client.so:graphics/wayland \
		libgcr-ui-3.so:security/gcr \
		libpolkit-agent-1.so:sysutils/polkit \
		libupower-glib.so:sysutils/upower \
		libhandy-1.so:x11-toolkits/libhandy
RUN_DEPENDS=	phoc:x11-wm/phoc \
		gnome-session:x11/gnome-session

USES=		compiler:c11 gettext gnome meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3
GL_SITE=	https://source.puri.sm
GL_ACCOUNT=	Librem5
GL_COMMIT=	6c873426a8f74a4ee0bcd0c2746636ae7f85928e
GL_TUPLE=	https://gitlab.gnome.org:GNOME:libgnome-volume-control:ae1a34aafce7026b8c0f65a43c9192d756fe1057:gvc/subprojects/gvc
SHEBANG_FILES=	build-aux/post_install.py
MESON_ARGS=	-Dgvc:alsa=false
GLIB_SCHEMAS=	sm.puri.phosh.enums.xml \
		sm.puri.phosh.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's/bash -l/sh -/' \
		-e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/data/phosh.in

.include <bsd.port.mk>
