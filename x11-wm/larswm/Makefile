# New ports collection makefile for: larswm
# Date created: Sat Oct  7 21:25:11 EDT 2000
# Whom: lab@fnurt.net
#
# $FreeBSD$
#

PORTNAME=	larswm
PORTVERSION=	7.0.13
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.fnurt.net/larswm/

MAINTAINER=	lab@fnurt.net

MAN1=		larswm.1
USE_IMAKE=	yes

XFREE86_HTML_MAN=	no

MAN1=		larsclock.1 larsremote.1 larswm.1

post-install:
.if !defined(NOPORTDOCS)
	$(MKDIR) $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_MAN) $(WRKSRC)/README $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_MAN) $(WRKSRC)/README.9wm $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_MAN) $(WRKSRC)/ChangeLog $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_MAN) $(WRKSRC)/keyboard_refcard.ms $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_MAN) $(WRKSRC)/larswmrc_refcard.ms $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_MAN) $(WRKSRC)/mouse_refcard.ms $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_SCRIPT) $(WRKSRC)/sample.barclock $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_SCRIPT) $(WRKSRC)/sample.barinfo $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_SCRIPT) $(WRKSRC)/sample.editor $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_DATA) $(WRKSRC)/sample.larswmrc $(PREFIX)/share/doc/$(PORTNAME)
	$(INSTALL_SCRIPT) $(WRKSRC)/sample.xsession $(PREFIX)/share/doc/$(PORTNAME)
.endif

.include <bsd.port.mk>
