# New ports collection makefile for:   qt-1.0
# Version required:	1.0
# Date created:		30 Jul 1996
# Whom:			searle@longacre.demon.co.uk
#
# $Id: Makefile,v 1.3 1996/10/02 02:22:27 jkh Exp $
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
	install -c $(WRKDIR)/qt-1.0/bin/moc $(X11BASE)/bin
	install -c $(WRKDIR)/qt-1.0/lib/libqt.so.1.0 $(X11BASE)/lib
	mv $(PREFIX)/lib/libqt.so.1.0 $(PREFIX)/lib/libqt.so.1.0
	/sbin/ldconfig -m $(PREFIX)/lib
	mkdir -p $(PREFIX)/include/X11/qt
	install $(WRKDIR)/qt-1.0/include/* $(PREFIX)/include/X11/qt
.if !defined(NOMANCOMPRESS)
	gzip -9nf $(WRKDIR)/qt-1.0/man/man1/*.1
	gzip -9nf $(WRKDIR)/qt-1.0/man/man3/*3qt
.endif
	install $(WRKDIR)/qt-1.0/man/man1/* $(PREFIX)/man/man1
	install $(WRKDIR)/qt-1.0/man/man3/* $(PREFIX)/man/man3

.include <bsd.port.mk>
