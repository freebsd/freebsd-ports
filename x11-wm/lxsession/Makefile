# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxsession
PORTVERSION=	0.4.6.1
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SF/lxde/LXSession%20%28session%20manager%29/LXSession%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LXDE Session Manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libhal.so:sysutils/hal \
		libgee-0.8.so:devel/libgee \
		libdbus-glib-1.so:devel/dbus-glib

USES=		gmake iconv localbase pkgconfig
USE_GNOME=	gtk20 intlhack libxslt
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

# Wrong versioning upstream
PORTSCOUT=	skipv:0.4.9.2

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
