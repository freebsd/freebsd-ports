# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	libxfce4util
PORTVERSION=	4.10.1
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Extension library for the Xfce desktop environment

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix perl5 pkgconfig tar:bzip2
USE_GNOME=	glib20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	configenv

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_CONFIGURE_ENABLE=	gtk-doc-html

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.mk>
