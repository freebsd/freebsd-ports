# New ports collection makefile for:	termit
# Date created:				2008/06/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	termit
PORTVERSION=	1.3.2
PORTREVISION=	5
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/chinsan/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small terminal emulator

MAKE_JOBS_SAFE=	yes

BUILD_DEPENDS=	vte:${PORTSDIR}/x11-toolkits/vte
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX=${LOCALBASE}

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=false
PLIST_SUB+=	NLS="@comment "
.endif

do-build:
	@(cd ${BUILD_WRKSRC}; \
	cmake ${CMAKE_ARGS} .; \
	${MAKE})

post-patch:
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e '1,3 d' ${WRKSRC}/doc/CMakeLists.txt
.endif

do-install:
	@(cd ${BUILD_WRKSRC}; \
	${MAKE} install)

.include <bsd.port.mk>
