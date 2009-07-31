# New ports collection makefile for:	Qwt
# Date created:		02 March 2002
# Whom:			Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	qwt
PORTVERSION=	4.2.0
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=qwt

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qwt widget library for technical purposes (old version)

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}"
MAKE_ENV+=	MOC="${MOC}" QTDIR="${QT_PREFIX}"
USE_LDCONFIG=	yes

QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
QMAKE=		${LOCALBASE}/bin/qmake

PORTSCOUT=	limit:^4\.
LATEST_LINK=	qwt4

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.man>

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} -unix)

post-configure:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|^LINK .*|LINK=${CXX}|' \
		${WRKSRC}/Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libqwt4.so.${PORTVERSION} ${PREFIX}/lib/libqwt4.so.${PORTVERSION:R:R}
	${LN} -fs ${PREFIX}/lib/libqwt4.so.${PORTVERSION:R:R} ${PREFIX}/lib/libqwt4.so
	${MKDIR} ${PREFIX}/include/qwt4
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qwt4
.for f in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/${f:S/Qwt4/Qwt/} ${PREFIX}/man/man3/${f}
.endfor

.include <bsd.port.post.mk>
