# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvidia-settings
PORTVERSION=	440.26
CATEGORIES=	x11

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for X NVidia driver

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	Nvidia driver is only available on x86

BUILD_DEPENDS=	${LOCALBASE}/include/dbus-1.0/dbus/dbus.h:devel/dbus
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjansson.so:devel/jansson \
		libvdpau.so:multimedia/libvdpau

USES=		gl gmake gnome pkgconfig gettext-runtime xorg
USE_GNOME=	gtk20 cairo gdkpixbuf2
USE_GL=		gl
USE_XORG=	x11 xext xv xxf86vm

USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIA

PLIST_FILES=	bin/nvidia-settings \
		man/man1/nvidia-settings.1.gz \
		lib/libnvidia-gtk2.so.${PORTVERSION} \
		share/applications/nvidia-settings.desktop \
		share/pixmaps/nvidia-settings.png

LDFLAGS+=	-pthread
LLD_UNSAFE=	yes
MAKE_ENV=	NV_USE_BUNDLED_LIBJANSSON=0 \
		NV_VERBOSE= \
		GTK3_AVAILABLE=0 \
		INSTALL_DOC_ARGS="${INSTALL_MAN:Ninstall}" \
		XNVCTRL_CFLAGS=-I${LOCALBASE}/include \
		XNVCTRL_LDFLAGS=-L${LOCALBASE}/lib

post-patch:	.SILENT
	${REINPLACE_CMD} \
		 -e '/^MANDIR/s|share/||' ${WRKSRC}/utils.mk
	${REINPLACE_CMD} -E -e 's,__(PIXMAP|UTILS)_PATH__/,,' \
		-e '/^Categories/ s,=.*,=  Settings;HardwareSettings;,' \
		${WRKSRC}/doc/nvidia-settings.desktop
	${REINPLACE_CMD} -e 's|/usr/share/nvidia/|${LOCALBASE}/share/doc/NVIDIA_GLX-1.0/|' \
		${WRKSRC}/src/gtk+-2.x/ctkappprofile.c

post-install:	.SILENT
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnvidia-gtk2.so.${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/doc/nvidia-settings.desktop \
		${STAGEDIR}/${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/nvidia-settings.png \
		${STAGEDIR}/${PREFIX}/share/pixmaps

.include <bsd.port.mk>
