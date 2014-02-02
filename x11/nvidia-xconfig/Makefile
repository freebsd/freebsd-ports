# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvidia-xconfig
PORTVERSION=	310.14
CATEGORIES=	x11
MASTER_SITES=	ftp://download.nvidia.com/XFree86/nvidia-xconfig/ \
		ftp://download1.nvidia.com/XFree86/nvidia-xconfig/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Tool to manipulate X configuration files for the NVidia driver

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		gmake

MAKE_ENV=	NV_VERBOSE= \
		STRIP_CMD=${TRUE} \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		prefix=${PREFIX}

PLIST_FILES=	bin/nvidia-xconfig \
		man/man1/nvidia-xconfig.1.gz

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^prefix/s/=/?&/' \
		 -e '/^MANDIR/s|share/||' ${WRKSRC}/utils.mk

.include <bsd.port.mk>
