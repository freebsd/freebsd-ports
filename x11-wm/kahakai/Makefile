# New ports collection makefile for:	kahakai
# Date created:		10 March 2004
# Whom:			Greg J. <xcas@cox.net>
#
# $FreeBSD$
#

PORTNAME=	kahakai
PORTVERSION=	0.6.2
PORTREVISION=	8
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kahakai window manager

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/artwiz-fonts:${PORTSDIR}/x11-fonts/artwiz-fonts

BROKEN=		Does not compile
#DEPRECATED=	Has been broken for more than 6 months
EXPIRATION_DATE=2008-09-19

DEPRECATED=	"Development ceased"

USE_AUTOTOOLS=	libtool:15
USE_PERL5_BUILD=yes
USE_BZIP2=	yes
USE_XORG=	x11 xft
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GCC=	3.4
USE_EFL=	imlib2

MAN1=		kahakai.1

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS=${PTHREAD_CFLAGS} \
		LDFLAGS=-L${LOCALBASE}/lib \
		LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha 4.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/tmp/ktest|${LOCALBASE}|' \
		${WRKSRC}/data/styles/Default.kastyle.in
	@${REINPLACE_CMD} -e 's|bool max|bool wmax|' \
		${WRKSRC}/src/Window.hh
	@${REINPLACE_CMD} -e 's|flags.max|flags.wmax|g' \
		${WRKSRC}/src/*.cc

pre-install:
	@${REINPLACE_CMD} -e 's|^None|globals()["None"]|' \
		${WRKSRC}/src/kahakai.py

.include <bsd.port.post.mk>
