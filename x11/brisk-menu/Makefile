# Created by: Eric Turgeon <ericbsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brisk-menu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Brisk Menu is an efficient menu for the MATE Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		gnome mate meson ninja pkgconfig gettext
MESON_ARGS=	--sysconfdir=${PREFIX}/etc

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_ARCH=	yes
USE_GNOME=	gtk30
USE_MATE= 	panel:lib
GLIB_SCHEMAS=	com.solus-project.brisk-menu.gschema.xml

.include <bsd.port.mk>
