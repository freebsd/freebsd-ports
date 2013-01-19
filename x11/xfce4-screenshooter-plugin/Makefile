# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$
#

PORTNAME=	xfce4-screenshooter-plugin
PORTVERSION=	1.8.1
PORTREVISION=	3
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/apps/xfce4-screenshooter/${PORTVERSION:R}
DISTNAME=	xfce4-screenshooter-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Desktop Screenshot plugin for Xfce

LIB_DEPENDS=	soup-2:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv libexo libmenu libutil panel
USE_PKGCONFIG=	build

MAN1=		xfce4-screenshooter.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTNAME%%|${PORTNAME}|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
