# $FreeBSD$

PORTNAME=	i3blocks
DISTVERSION=	1.4-93
DISTVERSIONSUFFIX=	-gfcee4e0
CATEGORIES=	x11

MAINTAINER=	coszminv@gmail.com
COMMENT=	Define blocks for your i3bar status line

LICENSE=	GPLv3

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Minbar1

PORTDOCS=	i3blocks.1.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/i3blocks.conf \
		${STAGEDIR}${PREFIX}/etc/i3blocks.conf.sample

.include <bsd.port.mk>
