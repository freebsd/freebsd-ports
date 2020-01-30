# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapps
PORTVERSION=	1.6.10
CATEGORIES=	x11

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-desktop libraries and common resources

LICENSE=	LGPL3

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libgnomekbdui.so:x11/libgnomekbd

USES=		gettext gnome meson pkgconfig python:build shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_LDCONFIG=	yes
USE_XORG=	x11
INSTALLS_ICONS=	yes
SHEBANG_FILES=	libxapp/g-codegen.py libxapp/install_generated_header.py \
		makedoc schemas/meson_install_schemas.py

post-extract:
# Do not install auxiliary scripts and adjust icons installation path
	@${RM} -r ${WRKSRC}/files/usr/bin
	@${MKDIR} ${WRKSRC}/files/${PREFIX}
	@${MV} ${WRKSRC}/files/usr/share ${WRKSRC}/files/${PREFIX}

post-patch:
# Do not build non-essential optional components for the moment
	@${REINPLACE_CMD} -E '/pygobject|status-applets/d' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
