# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvidia-settings
PORTVERSION=	355.11
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for X NVidia driver

LICENSE=	GPLv2

LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson \
		libvdpau.so:${PORTSDIR}/multimedia/libvdpau

USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIA

USE_GNOME=	gtk20
USES=		gmake pkgconfig
USE_GL=		gl
USE_XORG=	xext xv

PLIST_FILES=	bin/nvidia-settings \
		man/man1/nvidia-settings.1.gz \
		lib/libnvidia-gtk2.so.${PORTVERSION} \
		share/applications/nvidia-settings.desktop \
		share/pixmaps/nvidia-settings.png

LDFLAGS+=	-pthread
MAKE_ENV=	NV_USE_BUNDLED_LIBJANSSON=0 \
		NV_VERBOSE= \
		STRIP_CMD=${TRUE} \
		INSTALL_BIN_ARGS="${INSTALL_PROGRAM:Ninstall}" \
		INSTALL_DOC_ARGS="${INSTALL_MAN:Ninstall}" \
		X_CFLAGS=-I${LOCALBASE}/include \
		X_LDFLAGS=-L${LOCALBASE}/lib

post-patch:	.SILENT
	${REINPLACE_CMD} \
		 -e '/^MANDIR/s|share/||' ${WRKSRC}/utils.mk
	${REINPLACE_CMD} -E -e 's,__(PIXMAP|UTILS)_PATH__/,,' \
		-e '/^Categories/ s,=.*,=  Settings;HardwareSettings;,' \
		${WRKSRC}/doc/nvidia-settings.desktop

post-install:	.SILENT
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnvidia-gtk2.so.${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/doc/nvidia-settings.desktop \
		${STAGEDIR}/${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/nvidia-settings.png \
		${STAGEDIR}/${PREFIX}/share/pixmaps

.include <bsd.port.mk>
