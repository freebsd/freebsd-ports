# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME?=	qt
PORTVERSION?=	3.0.3
PORTREVISION=	3
CATEGORIES?=	x11-toolkits
MASTER_SITES=   ftp://ftp.trolltech.com/qt/source/ \
                ftp://ftp.chg.ru/pub/X11/qt/source/
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS=	mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

QT_PREFIX?=	${PREFIX}
USE_BZIP2=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-system-zlib -system-libpng -system-libjpeg -sm -qt-gif \
		-system-libmng -thread -disable-opengl -no-g++-exceptions \
		-enable-styles -enable-kernel -enable-widgets -enable-dialogs \
		-enable-iconview -enable-workspace -enable-network \
		-enable-canvas -enable-table -enable-xml -remote -static \
		-shared -no-nas-sound -no-stl -prefix ${QT_PREFIX} \
		-docdir ${QT_PREFIX}/share/doc/qt \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib
.if !defined(NO_DEBUG)
CONFIGURE_ARGS+= -debug
.endif
CONFIGURE_ENV=	${ECHO} yes | QTDIR=${WRKSRC}
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib
ALL_TARGET=	symlinks sub-src sub-tools

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

pre-configure:
	${RM} -fr ${WRKSRC}/examples ${WRKSRC}/tutorial

# The following target is necessary if qt30 is installed at the
# time the port build is started; it is related to the Makefiles
# having dependencies on these (installed) .prl files. --AlanE
pre-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/*.prl ${PREFIX}/lib

.include <bsd.port.post.mk>
