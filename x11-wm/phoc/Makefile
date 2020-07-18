# $FreeBSD$

PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	x11-wm

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	c7bbf4fcf917.diff:-p1 # https://source.puri.sm/Librem5/phoc/-/merge_requests/153
PATCHFILES+=	8e132eb25297.diff:-p1 # https://source.puri.sm/Librem5/phoc/-/merge_requests/153

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
GL_COMMIT=	cfc76a129d0b51c1f04f8eee73ef82a37ef9d769
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME}
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

post-extract:
# Avoid confusing Meson instead of forcing -Dembed-wlroots=disabled
	@${RMDIR} ${WRKSRC}/subprojects/wlroots
.if defined(PATCHFILES) && ${PATCHFILES:Mc7bbf4fcf917*}
# Pretend to be a regular file for vendor patch to apply as is
	@${ECHO_CMD} "Subproject commit 59f7adfe2977c3cb27a8def72c0d9fc2f2926c6d" \
		>${WRKSRC}/subprojects/wlroots
.endif

.include <bsd.port.mk>
