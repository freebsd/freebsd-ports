# New ports collection makefile for:	sakura
# Date created:				2008/06/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	sakura
PORTVERSION=	2.3.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	http://www.pleyades.net/david/projects/sakura/ \
		LOCAL/chinsan/${PORTNAME}/

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A terminal emulator based on GTK and VTE

USE_CMAKE=	yes
USE_GNOME=	vte
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

do-build:
	@(cd ${BUILD_WRKSRC}; \
	cmake ${CMAKE_ARGS} .; \
	${MAKE})

do-install:
	@(cd ${BUILD_WRKSRC}; \
	${MAKE} install)

.include <bsd.port.mk>
