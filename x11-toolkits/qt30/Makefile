# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME?=	qt
PORTVERSION?=	3.0.3
PORTREVISION=	2
CATEGORIES?=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/3.0/src
DISTNAME=	qt-copy-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS=	mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

#WRKSRC=		${WRKDIR}/qt-copy
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

# The following target is necessary if qt30 is installed at the
# time the port build is started; it is related to the Makefiles
# having dependencies on these (installed) .prl files. --AlanE
pre-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/*.prl ${PREFIX}/lib

# no reason to install CVS dirs
post-install:
	@-${RM} -fr ${PREFIX}/doc/html/CVS
	@-${RM} -fr ${PREFIX}/templates/CVS
	@-${RM} -fr ${PREFIX}/mkspecs/CVS ${PREFIX}/mkspecs/*/CVS

.include <bsd.port.post.mk>
