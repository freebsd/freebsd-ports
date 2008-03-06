# New ports collection makefile for:	nvidia-settings
# Date created:				15 Aug 2004
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nvidia-settings
PORTVERSION=	1.0
PORTREVISION=	13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_NVIDIA:S,$,XFree86/${PORTNAME}/,} \
		${MASTER_SITE_LOCAL:S,$,bland/,}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for X NVidia driver

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_GL=		gl

PLIST_FILES=	bin/nvidia-settings
MAN1=		nvidia-settings.1

MAKE_ENV=	ROOT=${PREFIX} \
		CC=${CC} \
		X11R6_LIB_DIR=${X11BASE}/lib \
		X11R6_INC_DIR=${X11BASE}/include \
		LDFLAGS="${PTHREAD_LIBS}"

pre-build:
	cd ${WRKSRC}/src/libXNVCtrl; \
	${CC} -c -I${X11BASE}/include -DCSRG_BASED -DFUNCPROTO=15 -DNARROWPROTO \
		-DXTHREADS -DXUSE_MTSAFE_API -DMALLOC_0_RETURNS_NULL NVCtrl.c; \
	${RM} -f libXNVCtrl.a; \
	ar clq libXNVCtrl.a NVCtrl.o; \
	ranlib libXNVCtrl.a

.include <bsd.port.mk>
