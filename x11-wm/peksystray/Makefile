# New ports collection makefile for:	PekSysTray
# Date created:				08 Jul 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	peksystray
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system tray dockapp similar to the GNOME notification area applet

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/peksystray

post-patch:
	@${REINPLACE_CMD} -e 's|@x_includes@||g ; \
		 s|@x_libraries@||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
