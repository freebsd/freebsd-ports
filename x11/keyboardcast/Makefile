# Created by: eimar.koort
# $FreeBSD$

PORTNAME=	keyboardcast
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	eimar.koort@gmail.com
COMMENT=	Broadcast keystrokes to multiple X windows for Gnome2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	ekoort

USES=		gnome pkgconfig xorg
USE_XORG=	xmu x11
USE_GNOME=	libwnck libglade2 gtk20
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
