# New ports collection makefile for:	termit
# Date created:				2008/06/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	termit
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/chinsan/${PORTNAME}/

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Small terminal emulator

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
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

PLIST=		${WRKDIR}/PLIST.DYN

do-build:
	@(cd ${BUILD_WRKSRC}; \
	cmake ${CMAKE_ARGS} .; \
	${MAKE})

pre-install:
	@${CP} ${PKGDIR}/pkg-plist ${WRKDIR}/PLIST.DYN
.if !defined(NOPORSDOCS)
	@${CAT} ${PKGDIR}/pkg-plist.DOC >> ${WRKDIR}/PLIST.DYN
.else
	@${REINPLACE_CMD} -e '1,3 d' ${WRKSRC}/doc/CMakeLists.txt
.endif

do-install:
	@(cd ${BUILD_WRKSRC}; \
	${MAKE} install)

.include <bsd.port.mk>
