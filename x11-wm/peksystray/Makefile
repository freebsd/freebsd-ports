PORTNAME=	peksystray
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Standalone system tray (notification area) dockapp
WWW=		https://peksystray.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2 xorg
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/peksystray

post-patch:
	@${REINPLACE_CMD} -e 's|@x_includes@|| ; s|@x_libraries@||' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/fprintf/s|, err|, "%s"&|' \
		${WRKSRC}/src/peksystray.c

.include <bsd.port.mk>
