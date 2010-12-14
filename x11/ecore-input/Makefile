# New ports collection makefile for:	ecore-input
# Date created:				16 May 2010
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	input
DISTVERSION=	1.0.0.beta
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2010-10-03/base/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${DISTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	Enlightenment core abstraction library (input module)

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	ecore libtool_hack
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_input
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <../../devel/ecore-main/Makefile.inc>

CONFIGURE_ARGS+=	--enable-ecore-input

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-input.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
