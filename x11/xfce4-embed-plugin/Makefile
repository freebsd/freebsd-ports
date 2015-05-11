# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-embed-plugin
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Embed arbitrary windows into the Xfce panel

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pkgconfig gettext-tools xfce tar:bzip2
USE_XORG=	x11
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	panel

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MNLS}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
.endif

.include <bsd.port.mk>
