PORTNAME=	xkbind
PORTVERSION=	2010.05.20
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}/source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Minimal keyboard layout indicator program
WWW=		https://xkbind.sourceforge.net/

LICENSE=	GPLv2

USES=		xorg
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME} lib/${PORTNAME}/app-defaults/Xkbind \
		share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS ChangeLog README README.utf8.ru THANKS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
