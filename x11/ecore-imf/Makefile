# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imf
PORTVERSION=	1.7.8
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	ecore-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (IMF module)

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	ecore libtool_hack
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_imf
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../../devel/ecore-main/Makefile.inc"

CONFIGURE_ARGS+=	--enable-ecore-con \
			--enable-ecore-imf

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_con/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_con/libecore_con\.la,-lecore_con,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-imf.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
