# New ports collection makefile for:	sisctrl
# Date created:				15 Aug 2004
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nvidia-settings
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://download.nvidia.com/XFree86/nvidia-settings/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     bland

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for XFree86/X.org NVidia driver

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes

PLIST_FILES=	bin/nvidia-settings
PORTDOCS=	nvidia-settings-user-guide.txt

MAKE_ENV=	ROOT=${PREFIX} \
		CC=${CC} \
		X11R6_LIB_DIR=${X11BASE}/lib \
		X11R6_INC_DIR=${X11BASE}/include

ONLY_FOR_ARCHS=	i386

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL} ${WRKSRC}/doc/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
