PORTNAME=	wmanager-addons
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://devel.ringlet.net/x11/wmanager-addons/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper scripts and documentation for the X11 window manager selector
WWW=		https://devel.ringlet.net/x11/wmanager-addons/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 uidfix
USE_PERL5=	run
NO_ARCH=	yes
MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in Changes README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
