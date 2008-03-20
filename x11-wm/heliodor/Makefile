# New ports collection makefile for:	heliodor
# Date created:				2007-02-05
# Whom:					Robert Noland <rnoland@2hip.net>
#
# $FreeBSD$
#

PORTNAME=	heliodor
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Heliodor Window Decorator

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/beryl.pc:${PORTSDIR}/x11-wm/beryl-core
RUN_DEPENDS+=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gnomecontrolcenter2 libwnck

WINDOWSETTINGSDATADIR=	\
	`pkg-config --variable=prefix gnome-window-settings-2.0`
WINDOWSETTINGSLIBDIR=	\
	`pkg-config --variable=libdir gnome-window-settings-2.0`

PLIST_SUB+=	WINDOWSETTINGSDATADIR="${WINDOWSETTINGSDATADIR}" \
		WINDOWSETTINGSLIBDIR="${WINDOWSETTINGSLIBDIR}"

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
