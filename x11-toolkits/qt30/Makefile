# New ports collection makefile for:   qt22
# Date created:		17 Jul 1999
# Whom:			imura@kml.cs.titech.ac.jp
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/
DISTNAME=	qt-x11-2.2.0

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_MESA=	yes
NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-system-zlib -system-libpng -system-jpeg -sm \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib
CONFIGURE_ENV=	QTDIR=${WRKSRC}
MAKE_ENV=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib

CONFIG=		${WRKSRC}/configs/freebsd-g++-${STATIC}

.if defined(QT_GIF_AVAILABLE) || defined(HAVE_UNISYS_LICENSE)
CONFIGURE_ARGS+=-gif
RESTRICTED=	"Requires a license from UNISYS"
.endif

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
	@${ECHO} "KDE2 snapshot 20000829A and later."
	@${FALSE}
.endif
.endif

pre-configure:
	@${CP} ${CONFIG} ${CONFIG}.new
	${SED} -e "s,gcc,${CC},g" ${CONFIG}.new | ${SED} -e "s,g\+\+,${CXX},g" | \
		${SED} -e "s,/usr/X11R6,${X11BASE},g" | ${SED} -e "s,-pipe -O2,${CXXFLAGS},g" > ${CONFIG}
	${PERL} -pi -e "s@VER_MAJ = 2@VER_MAJ = 4@g" ${WRKSRC}/src/Makefile.in
	${PERL} -pi -e "s@TARGET	= qt@TARGET = qt2@g" ${WRKSRC}/src/Makefile.in
	${PERL} -pi -e "s@TARGET\t= moc@TARGET = moc2@g" ${WRKSRC}/src/moc/Makefile.in
	${PERL} -pi -e "s@rm -f bin/moc@rm -f bin/moc2@g" ${WRKSRC}/Makefile
	${PERL} -pi -e "s@cp src/moc/moc bin/moc@cp src/moc/moc2  bin/moc2@g" ${WRKSRC}/Makefile
	${PERL} -pi -e "s@symlinks  src-moc src-mt sub-src sub-tools sub-tutorial sub-examples@symlinks src-moc src-mt sub-src sub-tools@g" ${WRKSRC}/Makefile
	${PERL} -pi -e "s@-L../lib@-L${WRKSRC}/lib@g" ${WRKSRC}/tools/designer/uic/Makefile.in

post-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} symlinks)

do-install:
	${MKDIR} ${PREFIX}/include/qt2
.for BIN in designer moc2 uic
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BIN} ${PREFIX}/bin
.endfor
.for SCRIPT in findtr qt20fix qtrename140
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${SCRIPT} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qt2
.for LIB in qt2 qutil
	${INSTALL_DATA} ${WRKSRC}/lib/lib${LIB}* ${PREFIX}/lib
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qt2/html/designer/figures
	${MKDIR} ${PREFIX}/share/doc/qt2/html/designer/stylesheet-images
	(cd ${WRKSRC} ; \
	${INSTALL_DATA} ANNOUNCE ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} FAQ ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} LICENSE.QPL ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} PORTING ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} README ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} README.QT ${PREFIX}/share/doc/qt2 ; \
	${INSTALL_DATA} doc/html/*.html doc/html/*.png ${PREFIX}/share/doc/qt2/html ; \
	${INSTALL_DATA} doc/html/designer/*.html ${PREFIX}/share/doc/qt2/html/designer ; \
	${INSTALL_DATA} doc/html/designer/figures/* ${PREFIX}/share/doc/qt2/html/designer/figures ; \
	${INSTALL_MAN} doc/man/man3/q* ${PREFIX}/man/man3 )
.endif

.if defined(WANT_STATIC)
post-install:
	@${PERL} -pi -e 's/libqt2\.so/libqt2.a/' ${TMPPLIST}
	@${PERL} -pi -e 's/.*libqt2\.a\.\d\n//' ${TMPPLIST}
	@${PERL} -pi -e 's/libqutil\.so/libqutil.a/' ${TMPPLIST}
	@${PERL} -pi -e 's/.*libqutil\.a\.\d\n//' ${TMPPLIST}
.endif

.include <bsd.port.mk>
