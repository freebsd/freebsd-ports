# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	locker
PORTVERSION=	0.2.1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3703/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Locker-${PORTVERSION}

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
USES=		pkgconfig gettext
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${MANPREFIX}/man

MAN1=		locker.1 lockerctl.1

NO_STAGE=	yes
.include <bsd.port.mk>
