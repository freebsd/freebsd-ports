# New ports collection makefile for:   qt22
# Date created:		17 Jul 1999
# Whom:			imura@kml.cs.titech.ac.jp
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	2.2.3
.if exists(${X11BASE}/lib/libXft.so) && !defined(NO_AA)
PORTREVISION=	1
.endif
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/
DISTNAME=	qt-x11-${PORTVERSION}

.if exists(${X11BASE}/lib/libXft.so) && !defined(NO_AA)
PATCHFILES=	qt-aa-${PORTVERSION}.diff.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	will
.endif

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	mng.0:${PORTSDIR}/graphics/libmng \
		png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

YES?=		/usr/bin/yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_MESA=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-system-zlib -system-libpng -system-jpeg -sm -gif \
		-system-libmng \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib
CONFIGURE_ENV=	${YES} yes | QTDIR=${WRKSRC}
MAKE_ARGS+=	MAKE="${GMAKE} -j2"
MAKE_ENV=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib

CONFIG=		${WRKSRC}/configs/freebsd-g++-${STATIC}

.if !defined(NOPORTDOCS)
.include "${.CURDIR}/files/manpages"
.endif

.if defined(WANT_STATIC)
STATIC=static
CONFIGURE_ARGS+=-static
.else
STATIC=shared
INSTALLS_SHLIB=yes
.endif

pre-fetch:
.if exists(${X11BASE}/lib/libqt2.so.3)
.if !defined(WANT_STATIC)
	@${ECHO} "An older version of QT2 is installed.  To avoid clobbering"
	@${ECHO} "that installation, deinstall it and then install this port."
	@${ECHO} "Note that this port contains beta-quality source code and"
	@${ECHO} "must be used only wherever absolutely needed, such as for"
	@${ECHO} "KDE 2.0 and later."
	@${FALSE}
.endif
.endif

pre-configure:
	@${CP} ${CONFIG} ${CONFIG}.new
	${SED} -e "s,gcc,${CC},g" -e "s,g\+\+,${CXX},g" -e "s,/usr/X11R6,${X11BASE},g" \
		-e "s,-pipe -O2,${CXXFLAGS},g" ${CONFIG}.new > ${CONFIG}
.if exists(${X11BASE}/lib/libXft.so) && !defined(NO_AA)
	@${CP} ${CONFIG} ${CONFIG}.new
	${SED} -e "s,= -lXext,= -lXft -lXext,g" -e "s,= -I${X11BASE}/include,= -DQT_XFT -I${X11BASE}/include,g" \
		${CONFIG}.new > ${CONFIG}
.endif
	${CP} ${WRKSRC}/src/Makefile.in ${WRKSRC}/src/Makefile.in.new
	${SED} -e "s,VER_MAJ = 2,VER_MAJ = 4,g" -e "s,TARGET	= qt,TARGET = qt2,g" ${WRKSRC}/src/Makefile.in.new > ${WRKSRC}/src/Makefile.in
	${PERL} -pi -e "s@TARGET\t= moc@TARGET = moc2@g" ${WRKSRC}/src/moc/Makefile.in
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.new
	${SED} -e "s,rm -f bin/moc,rm -f  bin/moc2,g" -e "s,cp src/moc/moc bin/moc,cp src/moc/moc2 bin/moc2,g" \
		-e "s,symlinks  src-moc src-mt sub-src sub-tools sub-tutorial sub-examples,symlinks src-moc src-mt sub-src sub-tools,g" \
		${WRKSRC}/Makefile.new > ${WRKSRC}/Makefile
	${PERL} -pi -e "s@-L../lib@-L${WRKSRC}/lib@g" ${WRKSRC}/tools/designer/uic/Makefile.in

post-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} symlinks)

do-install:
	${MKDIR} ${PREFIX}/include/qt2
	${MKDIR} ${PREFIX}/share/qt2/designer/templates
.for BIN in designer moc2 uic
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BIN} ${PREFIX}/bin
.endfor
.for SCRIPT in findtr qt20fix qtrename140
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${SCRIPT} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qt2
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libqt2.so.4 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libqutil.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libqt2.so.4 ${PREFIX}/lib/libqt2.so
	${LN} -sf ${PREFIX}/lib/libqutil.so.1 ${PREFIX}/lib/libqutil.so
.if defined(WANT_STATIC)
.for LIB in qt2 qutil
	${INSTALL_DATA} ${WRKSRC}/lib/lib${LIB}.a ${PREFIX}/lib
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/tools/designer/templates/* \
		${PREFIX}/share/qt2/designer/templates
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qt2
	(cd ${WRKSRC} ; \
	${INSTALL_DATA} ANNOUNCE ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} FAQ ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} LICENSE.QPL ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} PORTING ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} README ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} README.QT ${PREFIX}/share/doc/qt2 ; \
	( cd ${WRKSRC}/doc &&  ${TAR} -chf - html | \
		${TAR} --unlink -xf - -C ${PREFIX}/share/doc/qt2 ) ; \
	${INSTALL_MAN} doc/man/man3/q* ${PREFIX}/man/man3 )
.endif

.if defined(WANT_STATIC)
post-install:
	${CP} ${TMPPLIST} ${TMPPLIST}.new
	${SED} -e "s/libqt2\/.so/libqt2\.a/" -e "s/.*libqt2\.a\.\d\n//" -e "s/libqutil\.so/libqutil.a" \
		-e "s/.*libqutil\.a\.\d\n//" ${TMPPLIST}.new > ${TMPPLIST}
.endif

.include <bsd.port.mk>
