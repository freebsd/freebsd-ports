PORTNAME=	xfce4-taskmanager
PORTVERSION=	1.6.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Task manager for the Xfce desktop
WWW=		https://goodies.xfce.org/projects/applications/xfce4-taskmanager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-tools gnome localbase meson pkgconfig tar:xz xfce xorg
USE_GNOME=	glib20 gtk30 libwnck3
USE_XFCE=	libmenu xfconf
USE_XORG=	ice sm x11 xmu xt

MESON_ARGS=	-Dwnck=enabled \
		-Dx11=enabled

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
