# New ports collection makefile for: larswm
# Date created: Sat Oct  7 21:25:11 EDT 2000
# Whom: lab@fnurt.net
#
# $FreeBSD$
#

PORTNAME=	larswm
PORTVERSION=	7.2.8
CATEGORIES=	x11-wm
MASTER_SITES=	http://www-personal.umich.edu/~larsb/larswm/

MAINTAINER=	lab@fnurt.net

USE_IMAKE=	yes

MAN1=		larsclock.1 larsremote.1 larswm.1

PORTDOCS=	ChangeLog README README.9wm keyboard_refcard.ms \
		mouse_refcard.ms sample.barclock sample.larswmrc \
		sample.xmodmaprc sample.xsession

post-install:
.if !defined(NOPORTDOCS)
	@$(MKDIR) $(DOCSDIR)
.for file in ${PORTDOCS}
	$(INSTALL_DATA) $(WRKSRC)/${file} $(DOCSDIR)
.endfor
.endif

.include <bsd.port.mk>
