# -*-mode: makefile-*-
# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	3.2.3
CATEGORIES?=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/	\
		ftp://ftp.silug.org/pub/qt/		\
		ftp://ftp.bero.org/pub/qt/		\
		ftp://ftp.planetmirror.com.au/pub/trolltech/qt/
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A C++ X GUI toolkit

RUN_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

CONFLICTS=	linguist-0.* qt-2.* qt-designer-2.* xfmail-1.5.*

USE_BZIP2=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=yes

CONFIGURE_ARGS+=	-system-libpng -system-libjpeg -system-libmng	\
		-qt-imgfmt-png -qt-imgfmt-jpeg -qt-imgfmt-mng	\
		-system-zlib -no-nas-sound -sm -qt-gif -thread	\
		-fast -xinerama -no-g++-exceptions -no-stl	\
		${CUPS} -shared -prefix ${PREFIX} -datadir ${DATADIR} \
		-verbose -docdir ${DOCSDIR} \
		-plugindir ${PREFIX}/lib/plugins

CONFIGURE_ENV?=	${ECHO} yes | QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} \
		LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
ALL_TARGET=	sub-tools
EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
	--exclude '${DISTNAME}/mkspecs' --exclude '${DISTNAME}/qmake' \
	--exclude '${DISTNAME}/examples' --exclude '${DISTNAME}/tutorial' \
	--exclude '${DISTNAME}/extensions/nsplugin/src/[^q]*' \
	--exclude '${DISTNAME}/include/jri*' \
	--exclude '${DISTNAME}/include/np*'

.include <bsd.port.pre.mk>

# The previous Qt port versions installed qmake and qmake's specs under X11BASE
# The new devel/qmake port installs them under LOCALBASE. We can use
# either one here, but we prefer the newer:
.for d in ${X11BASE} ${LOCALBASE} ${PREFIX}
.	if exists($d/share/qt/mkspecs/freebsd-g++)
QTBASE=$d
PLATFORM=${QTBASE}/share/qt/mkspecs/freebsd-g++
.	endif
.endfor

.if defined(PLATFORM)
CONFIGURE_ARGS+=-platform ${PLATFORM}
.else
CONFIGURE_ARGS+=-platform ${LOCALBASE}/share/qt/mkspecs/freebsd-g++
.endif

.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/Xft
.else
CONFIGURE_ARGS+=-no-xft
.endif

.if defined(DEBUG)
CONFIGURE_ARGS+=-debug
.endif

.if !defined(WITHOUT_OPENGL)
USE_GL=		yes
.else
CONFIGURE_ARGS+=-disable-opengl
.endif # WITHOUT_OPENGL

.if !defined(WITHOUT_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
CUPS=	-cups -L${LOCALBASE}/lib -I${LOCALBASE}/include
.else
CUPS=
.endif

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

.if !defined(WITHOUT_XFT)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} '===> **************************************************'
	@${ECHO_MSG} '===> If you do not want to build QT with XFT support '
	@${ECHO_MSG} '===> press Ctrl-C and set WITHOUT_XFT'
	@${ECHO_MSG} '===> **************************************************'
.endif

.if ${XFREE86_VERSION} < 4
BROKEN=	"The QT ${PORTVERSION} port does not support any XFree86 < 4.x"
.endif # ${XFREE86_VERSION} < 4

.if exists(${X11BASE}/include/qt2/qapp.h)
BROKEN=	"You have QT2 headers installed!  Installing this port"
BROKEN+="will result in conflicts between QT3 and QT2!"
.endif

post-patch:
.if defined(PLATFORM)
	@${REINPLACE_CMD} -e 's|$$outpath/bin/qmake|${QTBASE}/bin/qmake|g' \
		${WRKSRC}/configure
.else
	@${REINPLACE_CMD} -e 's|$$outpath/bin/qmake|${LOCALBASE}/bin/qmake|g' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|^	cd qmake.*||' ${WRKSRC}/Makefile

post-build:
.for tool in makeqpf mergetr msg2qm qembed qvfb
	@cd ${WRKSRC}/tools/${tool}; ${SETENV} ${MAKE_ENV} ${MAKE}
.endfor
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${GREP} --mmap -F -l -- \
		"${PLATFORM}" | ${XARGS} ${REINPLACE_CMD} -e "s,${PLATFORM}/qmake.conf,," \
		-e "s,${PLATFORM},,"

# Work around qmake generated dependencies
pre-install:
	${MKDIR} ${PREFIX}/lib ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.prl ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/findtr ${PREFIX}/bin
.for tool in makeqpf mergetr msg2qm qembed qvfb
	${INSTALL_PROGRAM} ${WRKSRC}/tools/${tool}/${tool} ${PREFIX}/bin
.endfor

post-install:
	${RM} -f ${PREFIX}/lib/libqt-mt.la

.include <bsd.port.post.mk>
