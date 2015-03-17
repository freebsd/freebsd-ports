# Created by: ljo (orig)
# $FreeBSD$

PORTNAME=	xview-clients
PORTVERSION=	3.2.1.4.19c
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.physionet.org/physiotools/xview/src/ \
		http://komquats.com/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cy
DISTNAME=	xview-3.2p1.4-19c
EXTRACT_ONLY=	# empty

MAINTAINER=	cy@FreeBSD.org
COMMENT=	OpenLook applications and man pages

CONFLICTS=	props-1.0

MAKE_JOBS_UNSAFE=	yes
EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/x11-toolkits/xview:patch
CONFIGURE_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/x11-toolkits/xview:configure
LIB_DEPENDS=	libxview.so:${PORTSDIR}/x11-toolkits/xview

USES=		imake
USE_XORG=	x11 xext
ALL_TARGET=	Clients

BROKEN=		conflicts with its depends

.include <bsd.port.pre.mk>

IMAKECPPFLAGS+=	-DXVDestDir=${STAGEDIR}${PREFIX}

post-extract:
	${LN} -sf $$(${MAKE} -C ${PORTSDIR}/x11-toolkits/xview -V WRKDIR)/${DISTNAME} ${WRKSRC}

do-install:
	@cd ${WRKSRC}/clients; ${MAKE} install install.man

.include <bsd.port.post.mk>
