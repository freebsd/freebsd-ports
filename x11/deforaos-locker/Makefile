# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	locker
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3703/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Locker-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop screensaver

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libXss.so:x11/libXScrnSaver
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/Panel.pc:x11/deforaos-panel \
		xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

USE_GNOME=	gtk20
USES=		desktop-file-utils gettext pkgconfig
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

.include <bsd.port.mk>
