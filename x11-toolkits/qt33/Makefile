# -*-mode: makefile-*-
# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	3.3.2
PORTREVISION=	2
CATEGORIES?=	x11-toolkits
MASTER_SITES=	ftp://sunsite.rediris.es/mirror/Qt/source/ \
		ftp://ftp.iasi.roedu.net/mirrors/ftp.trolltech.com/qt/sources/	\
		ftp://ftp.ntua.gr/pub/X11/Qt/qt/source/		\
		ftp://ftp.tu-chemnitz.de/pub/Qt/source/ \
		ftp://ftp.silug.org/mirrors/ftp.trolltech.com/qt/source/ \
		ftp://ftp.planetmirror.com.au/pub/trolltech/qt/source/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/ \
		ftp://ftp.trolltech.com/qt/source/
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

CONFLICTS=	linguist-0.* qt-2.* qt-3.0.* \
		qt-3.1.* qt-3.2.* qt-designer-2.* xfmail-1.5.[0-5] \
		xfmail-1.5.5_[1-2]

USE_BZIP2=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=yes

CONFIGURE_ARGS+=	-system-libpng -system-libjpeg -system-libmng	\
		-qt-imgfmt-png -qt-imgfmt-jpeg -qt-imgfmt-mng	\
		-system-zlib -sm -qt-gif -thread \
		-fast -xinerama -no-g++-exceptions -stl -no-nis \
		${CUPS} -shared -prefix ${PREFIX} -datadir ${DATADIR} \
		-verbose -docdir ${DOCSDIR} -tablet -ipv6 \
		-plugindir ${PREFIX}/lib/plugins

CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
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

OPTIONS=	CUPS "Enable CUPS support" on \
		NAS "Enable NAS support" on \
		OPENGL "Enable OpenGL support" on \
		XFT "Enable Xft support" on

.include <bsd.port.pre.mk>

# The previous Qt port versions installed qmake and qmake's specs under X11BASE
# The new devel/qmake port installs them under LOCALBASE. We can use
# either one here, but we prefer the newer:
.for d in ${X11BASE} ${LOCALBASE} ${PREFIX}
.	if exists($d/share/qt/mkspecs/freebsd-g++/qplatformdefs.h)
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
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
.elseif defined(WITHOUT_XFT)
CONFIGURE_ARGS+=-no-xft
.endif

.if defined(WANT_QT_DEBUG)
CONFIGURE_ARGS+=-debug
.endif

.if !defined(WITHOUT_OPENGL)
USE_GL=		yes
.elseif defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=-disable-opengl
.endif # WITHOUT_OPENGL

.if !defined(WITHOUT_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
CUPS=	-cups -L${LOCALBASE}/lib -I${LOCALBASE}/include
.elseif defined(WITHOUT_CUPS)
CUPS=
.endif

.if !defined(WITHOUT_NAS)
LIB_DEPENDS+=	audio:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=-system-nas-sound
.elseif defined(WITHOUT_NAS)
CONFIGURE_ARGS+=-no-nas-sound
.endif

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
IGNORE=	"The QT ${PORTVERSION} port does not support any XFree86 < 4.x"
.endif

.if exists(${X11BASE}/include/qt2/qapp.h)
BROKEN=	"You have QT2 headers installed!  Installing this port"
BROKEN+="will result in conflicts between QT3 and QT2!"
.endif

post-patch:
.if defined(PLATFORM)
	@${REINPLACE_CMD} -e 's|$$outpath/bin/qmake|${QTBASE}/bin/qmake|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$OUTDIR/bin/qmake|${QTBASE}/bin/qmake|g' \
		${WRKSRC}/config.tests/unix/endian.test \
		${WRKSRC}/config.tests/unix/largefile.test \
		${WRKSRC}/config.tests/unix/ptrsize.test
.else
	@${REINPLACE_CMD} -e 's|$$outpath/bin/qmake|${LOCALBASE}/bin/qmake|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$OUTDIR/bin/qmake|${LOCALBASE}/bin/qmake|g' \
		${WRKSRC}/config.tests/unix/endian.test \
		${WRKSRC}/config.tests/unix/largefile.test \
		${WRKSRC}/config.tests/unix/ptrsize.test
.endif
	@${REINPLACE_CMD} -e 's|^	cd qmake.*||' ${WRKSRC}/Makefile

post-configure:
	@${REINPLACE_CMD} -e \
		's|/lib/pkgconfig/|/libdata/pkgconfig/|g' \
			${WRKSRC}/src/Makefile

post-build:
.for tool in makeqpf mergetr msg2qm qembed qvfb
	@cd ${WRKSRC}/tools/${tool}; ${SETENV} ${MAKE_ENV} ${MAKE}
.endfor
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${GREP} --mmap -F -l -- \
		"${PLATFORM}" | ${XARGS} ${REINPLACE_CMD} -e "s,${PLATFORM}/qmake.conf,," \
		-e "s,${PLATFORM},,"

# Work around qmake generated dependencies
pre-su-install:
	${MKDIR} ${PREFIX}/lib ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.prl ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/findtr ${PREFIX}/bin
.for tool in makeqpf mergetr msg2qm qembed qvfb
	${INSTALL_PROGRAM} ${WRKSRC}/tools/${tool}/${tool} ${PREFIX}/bin
.endfor

post-install:
	${RM} -f ${PREFIX}/lib/libqt-mt.la
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
