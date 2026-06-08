PORTNAME=	mate-menus
DISTVERSION=	1.28.1
CATEGORIES=	x11 mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the FreeDesktop Desktop Menu Spec
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig \
		python tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_GNOME=	glib20 intltool introspection:buid
USE_LDCONFIG=	yes
PORTSCOUT=	site:https://github.com/mate-desktop/mate-menus/releases/ limitw:1,even
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
