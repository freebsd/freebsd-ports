# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmanager-addons
PORTVERSION=	0.02
CATEGORIES=	x11-wm
MASTER_SITES=	http://devel.ringlet.net/x11/wmanager-addons/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper scripts and documentation for the X11 window manager selector

USES=		perl5
USE_PERL5=	run

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in Changes README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
