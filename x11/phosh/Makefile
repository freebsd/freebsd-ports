# $FreeBSD$

PORTNAME=	phosh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
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
		libhandy-0.0.so:x11-toolkits/libhandy
RUN_DEPENDS=	phoc:x11-wm/phoc \
		gnome-session:x11/gnome-session

USES=		compiler:c11 gnome meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3
GL_SITE=	https://source.puri.sm
GL_ACCOUNT=	Librem5
GL_COMMIT=	99d18088f1e44a19db870649559451e91adf204e
GL_TUPLE=	https://gitlab.gnome.org:GNOME:libgnome-volume-control:ae1a34aafce7026b8c0f65a43c9192d756fe1057:gvc/subprojects/gvc
MESON_ARGS=	-Dgvc:alsa=false
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-osk-stub \
		libexec/${PORTNAME} \
		${DATADIR}/phoc.ini \
		share/wayland-sessions/${PORTNAME}.desktop
GLIB_SCHEMAS=	sm.puri.phosh.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's/bash -l/sh -/' \
		-e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/data/phosh.in

.include <bsd.port.mk>
