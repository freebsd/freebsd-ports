PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	x11-wm

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	b37bf15194e6.patch:-p1 # https://source.puri.sm/Librem5/phoc/-/merge_requests/241

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

USES=		compiler:c11 gl gnome meson pkgconfig python:build shebangfix xorg
USE_GITLAB=	yes
USE_GL=		glesv2
USE_GNOME=	gnomedesktop3
USE_XORG=	pixman xcb
GL_SITE=	https://source.puri.sm
GL_ACCOUNT=	Librem5
GL_COMMIT=	f26fa0123742ba95d303ad552fc1f8d2d0117288
SHEBANG_FILES=	build-aux/post_install.py
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME}
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

post-extract:
# Avoid confusing Meson instead of forcing -Dembed-wlroots=disabled
	@${RMDIR} ${WRKSRC}/subprojects/wlroots
.if defined(PATCHFILES) && ${PATCHFILES:Mb37bf15194e6*}
# Pretend to be a regular file for vendor patch to apply as is
	@${ECHO_CMD} "Subproject commit 3d227f140e3c4af42d759477fc38e82a4c3dc4ef" \
		>${WRKSRC}/subprojects/wlroots
.endif

.include <bsd.port.mk>
