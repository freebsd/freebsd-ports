# New ports collection makefile for:	KDE libraries 2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	2.1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		mimelib.3:${PORTSDIR}/converters/kdesupport2

USE_OPENSSL=	yes
USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
SOMAJOR=	4
SOMINOR=	0
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

# Hack to make pthread support work correctly.
.if exists(${X11BASE}/lib/libqt2-mt.so)
.if exists(${X11BASE}/lib/libXThrStub.so)
QTNAME=		qt2-mt
.if ${OSVERSION} >= 500016
PTHREAD_CFLAGS=
PTHREAD_LIBS=	-lc_r
.else
PTHREAD_CFLAGS=	-D_THREAD_SAFE
PTHREAD_LIBS=	-pthread
.endif
.else
QTNAME=		qt2
PTHREAD_CFLAGS=
PTHREAD_LIBS=
.endif
.endif

CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
LDFLAGS+=	${PTHREAD_LIBS}

CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include -D_GETOPT_H ${PTHREAD_CFLAGS}" \
		MOC="${MOC}" LIBQT="-l${QTNAME}" LIBQTFILE="lib${QTNAME}" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++ ${PTHREAD_LIBS}" \
		LDFLAGS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++ ${PTHREAD_LIBS}"
USE_GMAKE=	yes
MAKE_ENV=	SOMAJOR="${SOMAJOR}" SOMINOR="${SOMINOR}"
PLIST_SUB+=	LIBVER="${SOMAJOR}"

pre-fetch:
.if ${OSVERSION} <= 410002
	@${ECHO}
	@${ECHO} "			NOTICE"
	@${ECHO}
	@${ECHO} "Your OpenSSL installation could be out of date.  This is"
	@${ECHO} "just a warning, but if your system's world was built on"
	@${ECHO} "sources earlier than August 20 along RELENG_4 or older,"
	@${ECHO} "then KDE2 will not build with SSL support."
	@${ECHO}
.endif

pre-configure:
.for NUM in 1 3
	(find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		"s@version-info ${NUM}:0@version-info ${SOMAJOR}:${SOMINOR}@g")
.endfor

post-configure:
	@${CP} ${WRKSRC}/libtool ${WRKSRC}/libtool.orig
	${SED} -e 's@\\\$$compiler_flags@\\\$$compiler_flags ${PTHREAD_LIBS}@g' ${WRKSRC}/libtool.orig \
		> ${WRKSRC}/libtool

post-install:
.for LIB in DCOP kab kdecore kdesu kdeui kfile kformula kio kjs \
	    kparts kspell ksycoca kjava
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.${SOMAJOR} ${PREFIX}/lib/lib${LIB}.so
.endfor
.for LIB in artsc artsflow artsflow_idl kmid kmedia2_idl qtmcop soundserver_idl
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.0 ${PREFIX}/lib/lib${LIB}.so
.endfor

.include <bsd.port.post.mk>
