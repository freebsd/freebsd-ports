# New ports collection makefile for:	kahakai
# Date created:		10 March 2004
# Whom:			Greg J. <xcas@cox.net>
#
# $FreeBSD$
#

PORTNAME=	kahakai
PORTVERSION=	0.6.2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	xcas@cox.net
COMMENT=	Kahakai window manager

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	\
	${X11BASE}/lib/X11/fonts/artwiz-fonts:${PORTSDIR}/x11-fonts/artwiz-fonts

DEPRECATED=	"Development ceased"

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GCC=	3.3

MAN1=		kahakai.1

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		CFLAGS=${PTHREAD_CFLAGS} \
		LDFLAGS=-L${X11BASE}/lib \
		LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/tmp/ktest|${X11BASE}|' \
		${WRKSRC}/data/styles/Default.kastyle.in

.include <bsd.port.post.mk>
