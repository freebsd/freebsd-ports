# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	fireflies
PORTVERSION=	2.07
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://somewhere.fscked.org/proj/fireflies/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension of xscreensaver

LIB_DEPENDS=	libgfx.so:graphics/libgfx

GNU_CONFIGURE=	yes
USE_GL=		yes
EXTRACT_AFTER_ARGS=--exclude '${DISTNAME}/libgfx*'

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/GL
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-bindir=${LOCALBASE}/bin/xscreensaver-hacks \
		--with-confdir=${LOCALBASE}/share/xscreensaver/config
PLIST_SUB=	VERSION=${PORTVERSION}

MAKE_ARGS=	CONFIGURE_ENV=${CONFIGURE_ENV:Q} \
		CONFIGURE_SCRIPT=${CONFIGURE_SCRIPT:Q} \
		CONFIGURE_ARGS=${CONFIGURE_ARGS:Q}

.include <bsd.port.mk>
