# New ports collection makefile for:   qt21
# Version required:	2.1.0 beta2
# Date created:		17 Jul 1999
# Whom:			imura@kml.cs.titech.ac.jp
#
# $FreeBSD$
#

DISTNAME=	qt-x11-2.1.0-beta3
PKGNAME=	qt-2.1.0b3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.troll.no/qt/source/

MAINTAINER=	imura@FreeBSD.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		GL.14:${PORTSDIR}/graphics/Mesa3

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-system-zlib -system-libpng -system-jpeg \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib
CONFIGURE_ENV=	QTDIR=${WRKSRC}
MAKE_ENV=	QTDIR=${WRKSRC}

WRKSRC=		${WRKDIR}/qt-2.1.0-beta3
CONFIG=		${WRKSRC}/configs/freebsd-g++-shared

.if defined(QT_GIF_AVAILABLE)
CONFIGURE_ARGS+=-gif
RESTRICTED=	'Requires a license from UNISYS'
.endif

.if !defined(NOPORTDOCS)
.include "files/manpages"
.endif

pre-configure:
	@${PERL} -pi -e "s,gcc,${CC},g" ${CONFIG}
	@${PERL} -pi -e "s,g\+\+,${CXX},g" ${CONFIG}
	@${PERL} -pi -e "s,/usr/X11R6,${X11BASE},g" ${CONFIG}
	@${PERL} -pi -e "s,-pipe -O2,${CXXFLAGS},g" ${CONFIG}

post-configure:
	@(cd ${WRKSRC} ; ${GMAKE} symlinks)

do-install:
	${MKDIR} ${PREFIX}/include/qt2
	(cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} bin/mergetr ${PREFIX}/bin ; \
	${INSTALL_PROGRAM} bin/moc ${PREFIX}/bin/moc2 ; \
	${INSTALL_PROGRAM} bin/msg2qm ${PREFIX}/bin ; \
	${INSTALL_SCRIPT} bin/findtr ${PREFIX}/bin ; \
	${INSTALL_SCRIPT} bin/qt20fix ${PREFIX}/bin ; \
	${INSTALL_SCRIPT} bin/qtrename140 ${PREFIX}/bin ; \
	${INSTALL_DATA} include/*.h ${PREFIX}/include/qt2 ; \
	${INSTALL_DATA} lib/* ${PREFIX}/lib )
	${LN} -sf libqt2.so.3 ${PREFIX}/lib/libqt2.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qt2/html
	(cd ${WRKSRC} ; \
	${INSTALL_DATA} ANNOUNCE ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} FAQ ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} LICENSE.QPL ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} PORTING ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} README ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} README.QT ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} doc/html/* ${PREFIX}/share/doc/qt2/html ; \
	${INSTALL_MAN} doc/man/man3/q* ${PREFIX}/man/man3 )
.endif

.include <bsd.port.mk>
