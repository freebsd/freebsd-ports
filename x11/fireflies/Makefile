# New ports collection makefile for:	fireflies
# Date created:				11 Feb 2006
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	fireflies
PORTVERSION=	2.07
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://somewhere.fscked.org/proj/fireflies/files/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Fireflies is a extention of xscreensaver

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/GL" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-bindir=${LOCALBASE}/bin/xscreensaver-hacks \
		--with-confdir=${LOCALBASE}/share/xscreensaver/config
PLIST_SUB=	VERSION=${PORTVERSION}

MAKE_ARGS=	CONFIGURE_ENV=${CONFIGURE_ENV:Q} \
		CONFIGURE_SCRIPT=${CONFIGURE_SCRIPT:Q} \
		CONFIGURE_ARGS=${CONFIGURE_ARGS:Q}

post-extract:
	(cd ${WRKSRC};  ${TAR} zxvpf libgfx-1.0.1.tar.gz)

.include <bsd.port.mk>
