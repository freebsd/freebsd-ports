# New ports collection makefile for:   qt20
# Version required:	2.0.2
# Date created:		17 Jul 1999
# Whom:			imura@cs.titech.ac.jp
#
# $FreeBSD$
#

DISTNAME=	qt-2.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.troll.no/qt/source/

MAINTAINER=	imura@FreeBSD.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

FORBIDDEN=	repository copied, awaiting upgrade

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-system-zlib -system-libpng \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib -lxpg4
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
VERSION=	2.02
.endif
PLIST_SUB=	VERSION=${VERSION}

.include "files/manpages"

do-install:
	@(cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} bin/mergetr ${PREFIX}/bin ; \
	${INSTALL_PROGRAM} bin/moc ${PREFIX}/bin/moc2 ; \
	${INSTALL_PROGRAM} bin/msg2qm ${PREFIX}/bin ; \
	${INSTALL_SCRIPT} bin/findtr ${PREFIX}/bin ; \
	${INSTALL_SCRIPT} bin/qt20fix ${PREFIX}/bin ; \
	${INSTALL_SCRIPT} bin/qtrename140 ${PREFIX}/bin ; \
	${INSTALL_DATA} lib/libqt2.so.${VERSION} ${PREFIX}/lib/libqt2.so.${VERSION} ; \
	${LN} -sf ${PREFIX}/lib/libqt2.so.${VERSION} ${PREFIX}/lib/libqt2.so ; \
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib ; \
	${MKDIR} ${PREFIX}/include/qt2 ; \
	${INSTALL_DATA} include/*.h ${PREFIX}/include/qt2 ; \
	${INSTALL_MAN} man/man1/moc.1 ${PREFIX}/man/man1/moc2.1 ; \
	${INSTALL_MAN} man/man3/q* ${PREFIX}/man/man3 )
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} ; \
	${MKDIR} ${PREFIX}/share/doc/qt2/html ; \
	${INSTALL_DATA} FAQ ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} LICENSE.QPL ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} README ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} README.QT ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} doc/* ${PREFIX}/share/doc/qt2/html )
.endif

.include <bsd.port.post.mk>
