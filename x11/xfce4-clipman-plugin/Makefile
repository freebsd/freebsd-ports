# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	1.2.3
PORTREVISION=	5
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 clipboard module for xfce4-panel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	UNIQUE
UNIQUE_DESC=	Enable Unique (single instance) support

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack glib20
USE_XFCE=	configenv libexo libmenu libutil panel xfconf
USE_XORG=	xtst
USES=		pkgconfig gettext pathfix

INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUNIQUE}
LIB_DEPENDS+=	unique-1:${PORTSDIR}/x11-toolkits/unique
CONFIGURE_ARGS+=	--enable-unique
.else
CONFIGURE_ARGS+=	--disable-unique
.endif

.include <bsd.port.mk>
