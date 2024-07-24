PORTNAME=	wmctrl-fork
DISTVERSION=	1.09.02
CATEGORIES=	x11
MASTER_SITES=	https://github.com/avysk/wmctrl-fork/releases/download/1.09.02/

MAINTAINER=	alexey@pentode.fi
COMMENT=	Command line tool to interact with an EWMH/NetWM compatible X managers
WWW=		https://github.com/avysk/wmctrl-fork

LICENSE=	GPLv2

USES=		gnome pkgconfig xorg

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_XORG=	ice sm x11 xmu xext xt
USE_GNOME=	glib20

PLIST_FILES=	bin/wmctrl share/man/man1/wmctrl.1.gz

.include <bsd.port.mk>
