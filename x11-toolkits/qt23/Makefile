# New ports collection makefile for:   qt201
# Version required:	2.0.1
# Date created:		17 Jul 1999
# Whom:			imura@cs.titech.ac.jp
#
# $FreeBSD$
#

DISTNAME=	qt-2.0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.troll.no/qt/source/

MAINTAINER=	imura@cs.titech.ac.jp

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-system-zlib -system-libpng
CONFIGURE_ENV=	QTDIR=${WRKSRC}
MAKE_ENV+=	QTDIR=${WRKSRC} SYS_CXX=${CXX} SYS_CC=${CC} SYS_CXXFLAGS="${CXXFLAGS}"

.include <bsd.port.pre.mk>

.if defined(QT_GIF_AVAILABLE)
CONFIGURE_ARGS+=-gif
RESTRICTED=	'Requires a license from UNISYS'
.endif

USE_NEWGCC=	YES

.if ${PORTOBJFORMAT} == "elf"
VERSION=	2
.else
VERSION=	2.01
.endif
PLIST_SUB=	VERSION=${VERSION}

.include "files/manpages"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mergetr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${PREFIX}/bin/moc2
	${INSTALL_PROGRAM} ${WRKSRC}/bin/msg2qm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/findtr ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qt20fix ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qtrename140 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libqt2.so.${VERSION} ${PREFIX}/lib/libqt2.so.${VERSION}
	${LN} -sf ${PREFIX}/lib/libqt2.so.${VERSION} ${PREFIX}/lib/libqt2.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/X11/qt2
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/X11/qt2
	${INSTALL_MAN} ${WRKSRC}/man/man1/moc.1 ${PREFIX}/man/man1/moc2.1
	${INSTALL_MAN} ${WRKSRC}/man/man3/q* ${PREFIX}/man/man3
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qt2/html
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/qt2
	${INSTALL_DATA} ${WRKSRC}/LICENSE.QPL ${PREFIX}/share/doc/qt2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qt2
	${INSTALL_DATA} ${WRKSRC}/README.QT ${PREFIX}/share/doc/qt2
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/qt2/html
.endif

.include <bsd.port.post.mk>
