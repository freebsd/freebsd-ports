# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-screenshooter-plugin
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/apps/xfce4-screenshooter/${PORTVERSION:R}
DISTNAME=	xfce4-screenshooter-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application and panel plugin to take screenshots

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack libxml2
USE_XFCE=	panel
USES=		pkgconfig gmake libtool gettext-tools xfce tar:bzip2
USE_XORG=	xfixes xext

OPTIONS_DEFINE=	NLS
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime
OPTIONS_SUB=	yes

.include <bsd.port.mk>
