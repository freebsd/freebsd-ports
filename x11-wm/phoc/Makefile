# $FreeBSD$

PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Phone compositor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.mutter.gschema.xml:x11-wm/mutter

USES=		compiler:c11 gl gnome meson pkgconfig xorg
USE_GITLAB=	yes
USE_GL=		glesv2
USE_GNOME=	gnomedesktop3
USE_XORG=	pixman
GL_SITE=	https://source.puri.sm
GL_ACCOUNT=	Librem5
GL_COMMIT=	99aea009aae6f827e3f86050a63a48707ac183f1
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME}
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

post-extract:
# Avoid confusing Meson instead of forcing -Dembed-wlroots=disabled
	@${RMDIR} ${WRKSRC}/subprojects/wlroots

.include <bsd.port.mk>
