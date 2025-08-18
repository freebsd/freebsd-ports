PORTNAME=	xfce4-panel
PORTVERSION=	4.20.5
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's panel
WWW=		https://gitlab.xfce.org/xfce/xfce4-panel

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu

USES=		compiler:c11 desktop-file-utils gettext-tools gnome meson \
		pathfix perl5 pkgconfig python:build shebangfix tar:bzip2 xfce \
		xorg
USE_GNOME=	glib20 gtk30 libwnck3
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XFCE=	garcon libexo windowing xdt xfconf
USE_XORG=	ice sm x11 xext

SHEBANG_FILES=	xdt-gen-visibility

MESON_ARGS=	-Ddbusmenu=enabled \
		-Dx11=enabled

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		GIR NLS VAPI WAYLAND
OPTIONS_DEFAULT=	GIR VAPI WAYLAND
OPTIONS_SUB=		yes

GIR_DESC=		Use Gobject Introspection

GIR_USE=		GNOME=introspection:build
GIR_MESON_TRUE=		introspection

NLS_USES=		gettext-runtime

VAPI_IMPLIES=		GIR
VAPI_USES=		vala:build
VAPI_MESON_ENABLED=	vala

WAYLAND_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
			libwayland-client.so:graphics/wayland
WAYLAND_MESON_ENABLED=	gtk-layer-shell wayland

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
