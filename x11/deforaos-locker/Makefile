# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	locker
PORTVERSION=	0.2.1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3703/
DISTNAME=	Locker-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop screensaver

LICENSE=	GPLv3

LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop \
		Xss:${PORTSDIR}/x11/libXScrnSaver
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/Panel.pc:${PORTSDIR}/x11/deforaos-panel \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes

MAKE_ENV+=	MANDIR=${MANPREFIX}/man

MAN1=		locker.1 lockerctl.1

.include <bsd.port.mk>
