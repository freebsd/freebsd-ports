# New ports collection makefile for:	nvidia-settings
# Date created:				15 Aug 2004
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nvidia-settings
PORTVERSION=	190.32
CATEGORIES=	x11
MASTER_SITES=	ftp://download.nvidia.com/XFree86/nvidia-settings/ \
		ftp://download1.nvidia.com/XFree86/nvidia-settings/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for X NVidia driver

USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_GL=		gl
USE_XORG=	xv

PLIST_FILES=	bin/nvidia-settings
MAN1=		nvidia-settings.1

MAKE_ENV=	ROOT=${PREFIX} \
		X11R6_LIB_DIR=${LOCALBASE}/lib \
		X11R6_INC_DIR=${LOCALBASE}/include \
		LDFLAGS="${PTHREAD_LIBS}"

WRKSRC=		${WRKDIR}/nvidia-settings-1.0

pre-build:
	cd ${WRKSRC}/src/libXNVCtrl; \
	${CC} -c -I${LOCALBASE}/include -DCSRG_BASED -DFUNCPROTO=15 -DNARROWPROTO \
		-DXTHREADS -DXUSE_MTSAFE_API -DMALLOC_0_RETURNS_NULL NVCtrl.c; \
	${RM} -f libXNVCtrl.a; \
	ar clq libXNVCtrl.a NVCtrl.o; \
	ranlib libXNVCtrl.a

.include <bsd.port.mk>
