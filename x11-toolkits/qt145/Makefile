# New ports collection makefile for:   qt
# Date created:		30 Jul 1996
# Whom:			searle@longacre.demon.co.uk
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	1.45
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/

PATCH_SITES=	ftp://ftp.kde.gr.jp/pub/qt/patch/
PATCHFILES=	qt-1.45-i18n-20000531.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	will@FreeBSD.org

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
.if defined(MAKE_JOBS)
MAKE_ARGS+=	MAKE="${GMAKE} -j${MAKE_JOBS}"
.else
MAKE_ARGS+=	MAKE="${GMAKE} -j2"
.endif
MAKE_ENV+=	QTDIR=${WRKSRC} CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -frerun-cse-after-loop" CC="${CC}"

VER_MAJ=	3
VER_MIN=	0
VERSION=	${VER_MAJ}

MAKE_ENV+=	VERSION="${VERSION}" VER_MIN=${VER_MIN} VER_MAJ=${VER_MAJ}
PLIST_SUB+=	VERSION="${VER_MAJ}"

.include <bsd.port.pre.mk>

MAN1=	moc.1
.include "${FILESDIR}/man3"

.if defined(WANT_STATIC)
STATIC=		static
.else
STATIC=		shared
INSTALLS_SHLIB=	yes
.endif

post-patch:
	@find ${WRKSRC}/src -name \*.h ! -name y.tab.h \
		| ${SED} -e "s,${WRKSRC},..," \
		| eval `${AWK} '{print "ln -sf",$$1,"${WRKSRC}/include"}'`

post-configure:
	@${PERL} -pi -e "s:g\+\+:${CXX}:g ; \
		s:/usr/X11R6:${PREFIX}:g ; \
		s:%%CXXFLAGS%%:${CXXFLAGS} -frerun-cse-after-loop:g ; \
		s:%%VERSION%%:${VERSION}:g" ${WRKSRC}/configs/freebsd-g++-${STATIC}
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} freebsd-g++-${STATIC})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${PREFIX}/bin
.if !defined(WANT_STATIC)
	@${INSTALL_DATA} ${WRKSRC}/lib/libqt.so.${VERSION} ${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libqt.so.${VERSION} ${PREFIX}/lib/libqt.so
.else
	@${INSTALL_DATA} ${WRKSRC}/lib/libqt.a ${PREFIX}/lib/libqt.a.${VERSION}
	@${LN} -sf ${PREFIX}/lib/libqt.a.${VERSION} ${PREFIX}/lib/libqt.a
.endif
	@${MKDIR} ${PREFIX}/include/X11/qt
	@${MKDIR} ${PREFIX}/share/doc/qt/html
	@(cd ${WRKSRC} ; \
	${INSTALL_DATA} include/*.h ${PREFIX}/include/X11/qt ; \
	${INSTALL_MAN} man/man1/* ${PREFIX}/man/man1 ; \
	${INSTALL_MAN} man/man3/* ${PREFIX}/man/man3 ; \
	${INSTALL_DATA} README ${PREFIX}/share/doc/qt ; \
	${INSTALL_DATA} README.QT ${PREFIX}/share/doc/qt ; \
	${INSTALL_DATA} html/* ${PREFIX}/share/doc/qt/html )

.if defined(WANT_STATIC)
post-install:
	@${PERL} -pi -e 's/libqt\.so/libqt.a/' ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
