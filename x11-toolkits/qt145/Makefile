# New ports collection makefile for:   qt
# Date created:		30 Jul 1996
# Whom:			searle@longacre.demon.co.uk
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	1.45
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/

MAINTAINER=	will@FreeBSD.org

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
MAKE_ENV+=	QTDIR=${WRKSRC} CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" CC="${CC}"

VER_MAJ=	3
VER_MIN=	0
VERSION=	${VER_MAJ}

MAKE_ENV+=	VERSION="${VERSION}" VER_MIN=${VER_MIN} VER_MAJ=${VER_MAJ}
PLIST_SUB+=	VERSION="${VER_MAJ}"

MAN1=	moc.1
.include "${.CURDIR}/files/man3"

post-configure:
	@${PERL} -pi -e "s:g\+\+:${CXX}:g" ${WRKSRC}/configs/freebsd-g++-shared
	@${PERL} -pi -e "s:/usr/X11R6:${PREFIX}:g" ${WRKSRC}/configs/freebsd-g++-shared
	@${PERL} -pi -e "s:%%CXXFLAGS%%:${CXXFLAGS}:g" ${WRKSRC}/configs/freebsd-g++-shared
	@${PERL} -pi -e "s:%%VERSION%%:${VERSION}:g" ${WRKSRC}/configs/freebsd-g++-shared
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} freebsd-g++-shared)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/moc $(PREFIX)/bin
	@${INSTALL_DATA} ${WRKSRC}/lib/libqt.so.${VERSION} $(PREFIX)/lib
	@${LN} -sf $(PREFIX)/lib/libqt.so.$(VERSION) $(PREFIX)/lib/libqt.so
	@${MKDIR} $(PREFIX)/include/X11/qt
	@${INSTALL_DATA} ${WRKSRC}/include/* $(PREFIX)/include/X11/qt
	@${INSTALL_MAN} ${WRKSRC}/man/man1/* $(PREFIX)/man/man1
	@${INSTALL_MAN} ${WRKSRC}/man/man3/* $(PREFIX)/man/man3
	@${MKDIR} ${PREFIX}/share/doc/qt/html
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/qt
	@${INSTALL_DATA} ${WRKSRC}/README.QT ${PREFIX}/share/doc/qt
	@${INSTALL_DATA} ${WRKSRC}/html/* ${PREFIX}/share/doc/qt/html

.include <bsd.port.mk>
