PORTNAME=	peksystray
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System tray dockapp similar to the GNOME notification area applet
WWW=		https://peksystray.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Last upstream release was in 2007
EXPIRATION_DATE=	2024-01-18

USES=		tar:bzip2 xorg
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/peksystray

post-patch:
	@${REINPLACE_CMD} -e 's|@x_includes@|| ; s|@x_libraries@||' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
