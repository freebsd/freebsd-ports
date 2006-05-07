# New ports collection makefile for:	fireflies
# Date created:				11 Feb 2006
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	fireflies
PORTVERSION=	2.07
CATEGORIES=	x11
MASTER_SITES=	http://somewhere.fscked.org/fireflies/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Fireflies is a extention of xscreensaver

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include/GL" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-bindir=${X11BASE}/bin/xscreensaver-hacks --with-confdir=${X11BASE}/share/xscreensaver/config
PLIST_SUB=	VERSION=${PORTVERSION}

post-extract:
	(cd ${WRKSRC};  ${TAR} zxvpf libgfx-1.0.1.tar.gz)

.include <bsd.port.mk>
