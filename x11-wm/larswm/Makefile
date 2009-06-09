# New ports collection makefile for: larswm
# Date created: Sat Oct  7 21:25:11 EDT 2000
# Whom: lab@fnurt.net
#
# $FreeBSD$
#

PORTNAME=	larswm
PORTVERSION=	7.5.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.safereconnect.com/fnurt/larswm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiling Window Manager for X

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xmu xt

MAN1=		larsclock.1 larsmenu.1 larsremote.1 larswm.1

MYPORTDOCS=	ChangeLog README README.9menu README.9wm \
		sample.larswmrc sample.xsession

post-install:
.if !defined(NOPORTDOCS)
	@$(MKDIR) $(DOCSDIR)
.for file in ${MYPORTDOCS}
	$(INSTALL_DATA) $(WRKSRC)/${file} $(DOCSDIR)
.endfor
.endif

.include <bsd.port.mk>
