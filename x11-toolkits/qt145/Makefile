# New ports collection makefile for:   qt-0.98
# Version required:	0.98
# Date created:		30 Jul 1996
# Whom:			searle@longacre.demon.co.uk
#
# $Id: Makefile,v 1.1.1.1 1996/07/31 00:20:49 chuckr Exp $
#

DISTNAME=	qt-0.98
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/

MAINTAINER=	searle@longacre.demon.co.uk

USE_GMAKE=	yes
WRKSRC=		$(WRKDIR)/$(DISTNAME)/arch/freebsd-shared
USE_X11=	yes

post-extract:
	cd $(WRKDIR)/$(DISTNAME)/arch; $(GMAKE) freebsd-shared
	
do-install:
	install -c $(WRKDIR)/qt-0.98/bin/moc $(X11BASE)/bin
	install -c $(WRKDIR)/qt-0.98/lib/libqt.so.0.908 $(X11BASE)/lib
	mv $(PREFIX)/lib/libqt.so.0.908 $(PREFIX)/lib/libqt.so.0.98
	/sbin/ldconfig -m $(PREFIX)/lib
	mkdir -p $(PREFIX)/include/X11/qt
	install $(WRKDIR)/qt-0.98/include/* $(PREFIX)/include/X11/qt
.if !defined(NOMANCOMPRESS)
	gzip -9nf $(WRKDIR)/qt-0.98/man/man1/*.1
	gzip -9nf $(WRKDIR)/qt-0.98/man/man3/*3qt
.endif
	install $(WRKDIR)/qt-0.98/man/man1/* $(PREFIX)/man/man1
	install $(WRKDIR)/qt-0.98/man/man3/* $(PREFIX)/man/man3

.include <bsd.port.mk>
