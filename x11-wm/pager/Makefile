# Created by: Michael Ebert <ebert@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	pager
PORTVERSION=	0.90.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.tuxfamily.org/sawfishpager/
DISTNAME=	sawfish-pager-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pager for sawfish without GNOME

BUILD_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish
RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish

USE_XZ=		yes
USE_GNOME=	gtk20
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/sawfish/sawfishpager \
		share/sawfish/lisp/sawfish/wm/ext/pager.jl \
		share/sawfish/lisp/sawfish/wm/ext/pager.jlc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sawfish/sawfishpager

.include <bsd.port.mk>
