# Created by: Serge Gagnon <gagnon__s@videotron.ca>
# $FreeBSD$

PORTNAME=	9box
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry

MAINTAINER=	ports@FreeBSD.org
COMMENT=	9box can "pack" windows inside itself

PLIST_FILES=	bin/9box
USE_GMAKE=	yes
USE_XORG=	xbitmaps x11 xt

BUILD_WRKSRC=	${WRKSRC}/src

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%CC%%|${CC}|g' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/9box ${PREFIX}/bin

.include <bsd.port.mk>
