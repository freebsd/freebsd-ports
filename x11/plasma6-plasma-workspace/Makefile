PORTNAME=	plasma-workspace
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE Plasma Workspace
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libicui18n.so:devel/icu \
		libKExiv2Qt6.so:graphics/libkexiv2-devel \
		libpipewire-0.3.so:multimedia/pipewire \
		libqalculate.so:math/libqalculate \
		libudev.so:devel/libudev-devd \
		libwayland-client.so:graphics/wayland \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon

RUN_DEPENDS=	${LOCALBASE}/bin/genv:sysutils/coreutils

USES=		cmake desktop-file-utils gettext gl kde:6 pkgconfig qt:6 \
		tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	activities activities-stats archive attica5 auth baloo5 \
		bookmarks colorscheme completion config configwidgets \
		coreaddons crash dbusaddons doctools filemetadata globalaccel \
		guiaddons holidays i18n iconthemes idletime itemmodels \
		itemviews jobwidgets kcmutils kdeclarative kio kirigami-addons \
		kirigami2 kpipewire kquickcharts kscreenlocker kwin \
		layer-shell-qt libkscreen libksysguard libplasma newstuff \
		notifications notifyconfig package parts phonon plasma5support prison \
		runner service solid sonnet statusnotifieritem svg \
		syntaxhighlighting texteditor textwidgets unitconversion \
		userfeedback wallet wayland widgetsaddons windowsystem xmlgui \
		ecm:build plasma-wayland-protocols:build
USE_QT=		5compat base declarative svg wayland
USE_XORG=	ice sm x11 xau xcb xcursor xext xfixes xft xi xrender xtst

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/startkde/startplasma.cpp

.include <bsd.port.mk>
