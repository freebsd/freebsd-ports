PORTNAME=	cinnamon-menus
PORTVERSION=	4.8.2
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for cinnamon
WWW=		https://github.com/linuxmint/cinnamon-menus

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

USES=		gnome meson pkgconfig

USE_GNOME=	glib20 introspection:build

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_LDCONFIG=	yes

.include <bsd.port.mk>
