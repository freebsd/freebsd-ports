# Created by: Eric Turgeon <ericbsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brisk-menu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Brisk Menu is an efficient menu for the MATE Desktop

LICENSE=	GPLv2+ CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE
LICENSE_FILE_CC-BY-SA-4.0=	${WRKSRC}/LICENSE.CC-BY-SA-4.0

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		compiler:c11 gettext gnome mate meson ninja pkgconfig xorg
MESON_ARGS=	--sysconfdir=${PREFIX}/etc

USE_GITHUB=	yes
GH_ACCOUNT=	getsolus

USE_GNOME=	gtk30
USE_MATE=	menus panel
GLIB_SCHEMAS=	com.solus-project.brisk-menu.gschema.xml
USE_XORG=	x11

.if exists(/usr/bin/ld.lld)
LDFLAGS+=	-fuse-ld=lld
.else
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
.endif

.include <bsd.port.mk>
