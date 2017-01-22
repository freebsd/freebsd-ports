# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsibreak
DISTVERSION=	0.11
PORTREVISION=	4
CATEGORIES=	x11 kde
MASTER_SITES=	LOCAL/crees/${PORTNAME} \
		http://pkgs.fedoraproject.org/repo/pkgs/rsibreak/rsibreak-0.11.tar.bz2/d5dd540efd18900aa508eee381bcaafd/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	KDE RSI prevention tool

USES=		cmake gettext kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib dbus gui network svg xml \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11

.include <bsd.port.mk>
