# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdkbuilder
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general ide tool for GTK+/VDK

LIB_DEPENDS=	vdk-2.7:${PORTSDIR}/x11-toolkits/vdk

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-opt=no
USE_LDCONFIG=	yes

MAN1=		vdkb2.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|cflag="-s"|cflag="$$CXXFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|: install-IconsDATA|:|g' ${WRKSRC}/data/res/Makefile.in

.include <bsd.port.mk>
