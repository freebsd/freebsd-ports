PORTNAME=	cliphist
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	8
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Wayland clipboard manager with support for multimedia
WWW=		https://github.com/sentriz/cliphist

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	go.senan.xyz/cliphist

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	readme.md

OPTIONS_DEFINE=	DOCS FZF
OPTIONS_DEFAULT=FZF

FZF_DESC=		Script with only unique lines and previews

FZF_RUN_DEPENDS=	fzf:textproc/fzf \
			wl-copy:x11/wl-clipboard
FZF_PLIST_FILES=	bin/${PORTNAME}-fzf

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-FZF-on:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/${FZF_PLIST_FILES:T} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
