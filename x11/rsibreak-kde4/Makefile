# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsibreak
DISTVERSION=	0.11
CATEGORIES=	x11 kde
MASTER_SITES=	LOCAL/crees/${PORTNAME} \
		http://pkgs.fedoraproject.org/repo/pkgs/rsibreak/rsibreak-0.11.tar.bz2/d5dd540efd18900aa508eee381bcaafd/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	KDE RSI prevention tool

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USES=		cmake gettext
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
