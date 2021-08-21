PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	x11-wm

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	4912c5a9454b.patch:-p1 # https://gitlab.gnome.org/World/Phosh/phoc/-/merge_requests/241
PATCHFILES+=	00e5da6dd7a2.patch:-p1 # https://gitlab.gnome.org/World/Phosh/phoc/-/merge_requests/241
PATCHFILES+=	b278fd6b4f57.patch:-p1 # https://gitlab.gnome.org/World/Phosh/phoc/-/merge_requests/241
PATCHFILES+=	3f418c11d813.patch:-p1 # https://gitlab.gnome.org/World/Phosh/phoc/-/merge_requests/241
PATCHFILES+=	4a688ffec053.patch:-p1 # https://gitlab.gnome.org/World/Phosh/phoc/-/merge_requests/241
PATCHFILES+=	8010e3d9ca00.patch:-p1 # https://gitlab.gnome.org/World/Phosh/phoc/-/merge_requests/241
PATCHFILES+=	8ec2886673d3.patch:-p1 # https://gitlab.gnome.org/World/Phosh/phoc/-/merge_requests/241

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Phone compositor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wlroots>=0.14.0:x11-toolkits/wlroots
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
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/Phosh
GL_COMMIT=	527689df1300277af2cdfc872474c8322e38f690
SHEBANG_FILES=	build-aux/post_install.py
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME}
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

post-extract:
# Avoid confusing Meson instead of forcing -Dembed-wlroots=disabled
	@${RMDIR} ${WRKSRC}/subprojects/wlroots
.if defined(PATCHFILES) && ${PATCHFILES:M4912c5a9454b*}
# Pretend to be a regular file for vendor patch to apply as is
	@${ECHO_CMD} "Subproject commit 3d227f140e3c4af42d759477fc38e82a4c3dc4ef" \
		>${WRKSRC}/subprojects/wlroots
.endif

.include <bsd.port.mk>
