# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	peksystray
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System tray dockapp similar to the GNOME notification area applet

LICENSE=	GPLv2

USES=		tar:bzip2 xorg
USE_XORG=	x11 ice sm
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/peksystray

post-patch:
	@${REINPLACE_CMD} -e 's|@x_includes@|| ; s|@x_libraries@||' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
