# New ports collection makefile for:	kgamma
# Date created:		21 July 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		kgamma
PORTVERSION=		1.0.1
CATEGORIES=		x11 kde
MASTER_SITES=		http://download.berlios.de/kgamma/
DISTNAME=		${PORTNAME}-${PORTVERSION:S/.p./_pre/}

MAINTAINER=		arved@FreeBSD.org

LIB_DEPENDS= 		intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
