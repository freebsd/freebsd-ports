# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdesktop
PORTVERSION=	0.0.10
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4293/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	libDesktop-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop library

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem

USE_GNOME=	gtk20
USES=		pkgconfig
USE_LDCONFIG=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh

.include <bsd.port.mk>
