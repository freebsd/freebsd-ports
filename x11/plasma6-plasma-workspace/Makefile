PORTNAME=	plasma-workspace
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE Plasma Workspace
MAINTAINER=	kde@FreeBSD.org

PATCH_SITES=	https://invent.kde.org/plasma/plasma-workspace/-/commit/
PATCHFILES+=	8047b93defa4be4c6c1864e93c41fddcef2969bb.patch:-p1 # CVE-2024-36041
PATCHFILES+=	a061b08e90ec5554d5ff8c57ae1218130c76e27a.patch:-p1 # CVE-2024-36041

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libicui18n.so:devel/icu \
		libpipewire-0.3.so:multimedia/pipewire \
		libqalculate.so:math/libqalculate \
		libudev.so:devel/libudev-devd \
		libwayland-client.so:graphics/wayland \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon

RUN_DEPENDS=	${LOCALBASE}/bin/genv:sysutils/coreutils

USES=		cmake desktop-file-utils gettext gl kde:6 pkgconfig python \
		qt:6 shebangfix tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	activities activities-stats archive attica auth baloo \
		bookmarks colorscheme completion config configwidgets \
		coreaddons crash dbusaddons doctools filemetadata globalaccel \
		guiaddons holidays i18n iconthemes idletime itemmodels \
		itemviews jobwidgets kcmutils kdeclarative kio kirigami-addons \
		kirigami2 kpipewire kquickcharts kscreenlocker kwin \
		layer-shell-qt libkexiv2 libkscreen libksysguard libplasma \
		newstuff notifications notifyconfig package parts phonon \
		plasma5support prison runner service solid sonnet \
		statusnotifieritem svg syntaxhighlighting texteditor \
		textwidgets unitconversion userfeedback wallet wayland \
		widgetsaddons windowsystem xmlgui \
		ecm:build plasma-wayland-protocols:build
USE_QT=		5compat base declarative svg wayland
USE_XORG=	ice sm x11 xau xcb xcursor xext xfixes xft xi xrender xtst
SHEBANG_FILES=	components/calendar/kconf_update/migrate-calendar-to-plugin-id.py

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/startkde/startplasma.cpp

.include <bsd.port.mk>
