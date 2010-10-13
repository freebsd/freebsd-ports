# New ports collection makefile for:	nvidia-xconfig
# Date created:				10 Dec 2005
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nvidia-xconfig
PORTVERSION=	256.53
CATEGORIES=	x11
MASTER_SITES=	ftp://download.nvidia.com/XFree86/nvidia-xconfig/ \
		ftp://download1.nvidia.com/XFree86/nvidia-xconfig/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Tool to manipulate X configuration files for the NVidia driver

USE_BZIP2=	yes
USE_GMAKE=	yes

MAKE_ENV=	NV_VERBOSE= \
		STRIP_CMD=${TRUE} \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		prefix=${PREFIX}

PLIST_FILES=	bin/nvidia-xconfig
MANCOMPRESSED=	yes
MAN1=		nvidia-xconfig.1

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^prefix/s/=/?&/' \
		 -e '/^mandir/s|share/||' ${WRKSRC}/utils.mk

.include <bsd.port.mk>
