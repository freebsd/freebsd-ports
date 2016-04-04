# Created by: Matt Lancereau
# $FreeBSD$

PORTNAME=	xfce4-terminal
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack vte libxml2
USE_XFCE=	libmenu
USE_XORG=	x11
USES=		pkgconfig gmake gettext-tools xfce tar:bzip2

CONFIGURE_ARGS=	--without-gnome-default-appsdir

OPTIONS_DEFINE=	NLS
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|	terminal||; \
		s|po \\|terminal|' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
