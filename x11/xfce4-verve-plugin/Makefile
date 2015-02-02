# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	verve-plugin
PORTVERSION=	1.0.1
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION:R}
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Command line plugin for the Xfce Desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig tar:bzip2
USE_GNOME=	glib20 intltool intlhack
USE_XFCE=	configenv libexo libmenu libutil panel

CONFIGURE_ARGS=--enable-dbus

OPTIONS_DEFINE=	NLS
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
OPTIONS_SUB=	yes

.include <bsd.port.mk>
