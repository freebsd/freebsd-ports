PORTNAME=	larswm
PORTVERSION=	7.5.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiling Window Manager for X
WWW=		https://sourceforge.net/projects/larswm/

DEPRECATED=	Last upstream release was in 2010
EXPIRATION_DATE=	2024-01-18

USES=		imake xorg
USE_XORG=	ice sm x11 xext xmu xt

PORTDOCS=	ChangeLog README README.9menu README.9wm \
		sample.larswmrc sample.xsession
PLIST_FILES=	bin/larsclock bin/larsmenu bin/larsremote bin/larswm \
		man/man1/larsclock.1.gz man/man1/larsmenu.1.gz \
		man/man1/larsremote.1.gz man/man1/larswm.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
