# New ports collection makefile for:   vdkbuilder
# Date created:        29 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdkbuilder
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}2-${PORTVERSION}
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general ide tool for GTK+/VDK

LIB_DEPENDS=	vdk.6:${PORTSDIR}/x11-toolkits/vdk

USE_GNOME=	gnometarget gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-opt=no
USE_LDCONFIG=	yes

MAN1=		vdkb2.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|cflag="-s"|cflag="$$CXXFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|: install-IconsDATA|:|g' ${WRKSRC}/data/res/Makefile.in

.include <bsd.port.mk>
