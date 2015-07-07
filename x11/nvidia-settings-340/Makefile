# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvidia-settings
PORTVERSION=	340.76
CATEGORIES=	x11
MASTER_SITES=	ftp://download.nvidia.com/XFree86/nvidia-settings/ \
		ftp://download1.nvidia.com/XFree86/nvidia-settings/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for X NVidia driver

LICENSE=	GPLv2

LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson \
		libvdpau.so:${PORTSDIR}/multimedia/libvdpau

USE_GNOME=	gtk20
USES=		gmake pkgconfig tar:bzip2
USE_GL=		gl
USE_XORG=	xv xext

PLIST_FILES=	bin/nvidia-settings \
		man/man1/nvidia-settings.1.gz

LDFLAGS+=	-Wl,--as-needed
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

.include <bsd.port.mk>
