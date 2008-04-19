# New ports collection makefile for:	PekSysTray
# Date created:				08 Jul 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	peksystray
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system tray dockapp similar to the GNOME notification area applet

USE_BZIP2=	yes
USE_XORG=	x11 ice sm
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/peksystray

post-patch:
	@${REINPLACE_CMD} -e 's|@x_includes@||g ; \
		 s|@x_libraries@||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
