# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xkbind
PORTVERSION=	2010.05.20
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}/source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Minimal keyboard layout indicator program

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		xorg
USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME} lib/${PORTNAME}/app-defaults/Xkbind \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS ChangeLog README README.utf8.ru THANKS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
