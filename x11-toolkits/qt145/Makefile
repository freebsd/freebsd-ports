# New ports collection makefile for:   qt-1.0
# Version required:	1.0
# Date created:		30 Jul 1996
# Whom:			searle@longacre.demon.co.uk
#
# $Id: Makefile,v 1.5 1996/10/11 22:10:23 chuckr Exp $
#

DISTNAME=	qt-1.0
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/

MAINTAINER=	searle@longacre.demon.co.uk

USE_GMAKE=	yes
WRKSRC=		$(WRKDIR)/$(DISTNAME)/arch/freebsd-gcc-shared
USE_X11=	yes

post-extract:
	cd $(WRKDIR)/$(DISTNAME)/arch; $(GMAKE) freebsd

do-install:
	${INSTALL_PROGRAM} $(WRKDIR)/qt-1.0/bin/moc $(X11BASE)/bin
	${INSTALL_DATA} $(WRKDIR)/qt-1.0/lib/libqt.so.1.0 $(X11BASE)/lib
	/sbin/ldconfig -m $(PREFIX)/lib
	mkdir -p $(PREFIX)/include/X11/qt
	${INSTALL_DATA} $(WRKDIR)/qt-1.0/include/* $(PREFIX)/include/X11/qt
.if !defined(NOMANCOMPRESS)
	${GZIP_CMD} $(WRKDIR)/qt-1.0/man/man1/*.1
	${GZIP_CMD} $(WRKDIR)/qt-1.0/man/man3/*.3qt
.endif
	${INSTALL_MAN} $(WRKDIR)/qt-1.0/man/man1/* $(PREFIX)/man/man1
	${INSTALL_MAN} $(WRKDIR)/qt-1.0/man/man3/* $(PREFIX)/man/man3
	mkdir -p ${PREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKDIR}/qt-1.0/README ${PREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKDIR}/qt-1.0/README.QT ${PREFIX}/share/doc/qt

.include <bsd.port.mk>
