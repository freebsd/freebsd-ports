# New ports collection makefile for:   vdkbuilder
# Date created:        29 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdkbuilder
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general ide tool for GTK+/VDK

LIB_DEPENDS=	vdk.6:${PORTSDIR}/x11-toolkits/vdk

BROKEN=		Incomplete pkg-plist

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk20 lthack
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-opt=no
INSTALLS_SHLIB=	yes

MAN1=		vdkb2.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|cflag="-s"|cflag="$$CXXFLAGS"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
