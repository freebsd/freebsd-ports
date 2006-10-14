# New ports collection makefile for:	fireflies
# Date created:				11 Feb 2006
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	fireflies
PORTVERSION=	2.07
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://somewhere.fscked.org/fireflies/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Fireflies is a extention of xscreensaver

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include/GL" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-bindir=${LOCALBASE}/bin/xscreensaver-hacks \
		--with-confdir=${LOCALBASE}/share/xscreensaver/config
PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

post-extract:
	(cd ${WRKSRC};  ${TAR} zxvpf libgfx-1.0.1.tar.gz)

.include <bsd.port.post.mk>
