# New ports collection makefile for:	kahakai
# Date created:		10 March 2004
# Whom:			Greg J. <xcas@cox.net>
#
# $FreeBSD$
#

PORTNAME=	kahakai
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	xcas@cox.net
COMMENT=	Kahakai window manager

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	\
	${X11BASE}/lib/X11/fonts/artwiz-fonts:${PORTSDIR}/x11-fonts/artwiz-fonts

DEPRECATED=	"Development ceased"

USE_PERL5_BUILD=yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GCC=	3.4

MAN1=		kahakai.1

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		CFLAGS=${PTHREAD_CFLAGS} \
		LDFLAGS=-L${X11BASE}/lib \
		LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha 4.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/tmp/ktest|${X11BASE}|' \
		${WRKSRC}/data/styles/Default.kastyle.in
	@${REINPLACE_CMD} -e 's|bool max|bool wmax|' \
		${WRKSRC}/src/Window.hh
	@${REINPLACE_CMD} -e 's|flags.max|flags.wmax|g' \
		${WRKSRC}/src/*.cc

pre-install:
	@${REINPLACE_CMD} -e 's|^None|globals()["None"]|' \
		${WRKSRC}/src/kahakai.py

.include <bsd.port.post.mk>
