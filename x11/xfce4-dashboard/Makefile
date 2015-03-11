# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	dashboard
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	http://xfdashboard.froevel.de/releases/
PKGNAMEPREFIX=	xfce4-
DISTNAME=	xfdashboard-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GNOME shell like dashboard for the Xfce desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
	libclutter-1.0.so:${PORTSDIR}/graphics/clutter
RUN_DEPENDS=	gnome-icon-theme-symbolic>=3.6.2:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic

GNU_CONFIGURE=	yes
USES=	pkgconfig libtool gmake perl5 gettext xfce tar:bzip2
USE_GNOME=	glib20 libwnck intltool intlhack
USE_XFCE=	garcon
USE_XORG=	x11 xcomposite xdamage
USE_GL=	gl
INSTALLS_ICONS=	yes

post-patch:
	${FIND} ${WRKSRC}/data/themes -type f -name '*.css' \
		| ${XARGS} ${REINPLACE_CMD} -i "" 's|gtk-home|go-home|'

.include <bsd.port.mk>
