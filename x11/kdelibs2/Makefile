# New ports collection makefile for:	KDE libraries 2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	20000724A
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		qt2.4:${PORTSDIR}/x11-toolkits/qt22 \
		kde-qt-addon.4:${PORTSDIR}/x11-toolkits/kde-qt-addon

WRKSRC=		${WRKDIR}/${PORTNAME}
MOC?=		${X11BASE}/bin/moc2
SOMAJOR=	4
SOMINOR=	0
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} --enable-shared \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib -lqt2 -ljpeg -lgcc -lstdc++"
USE_GMAKE=	yes
MAKE_ENV=	SOMAJOR="${SOMAJOR}" SOMINOR="${SOMINOR}"
PLIST_SUB+=	LIBVER="${SOMAJOR}"

pre-configure:
.for NUM in 1 3
	(find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		"s@version-info ${NUM}:0@version-info ${SOMAJOR}:${SOMINOR}@g")
.endfor

post-install:
.for LIB in DCOP kab kdecore kdesu kdeui kfile kformula kio kjs kmid \
	    kparts kspell ksycoca kjava
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.${SOMAJOR} ${PREFIX}/lib/lib${LIB}.so
.endfor
.for LIB in artsc artsflow artsflow_idl kmedia2_idl qtmcop soundserver_idl
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.0 ${PREFIX}/lib/lib${LIB}.so
.endfor

pre-install:
	@(find ${WRKSRC} -name CVS | xargs rm -rf)

.include <bsd.port.mk>
