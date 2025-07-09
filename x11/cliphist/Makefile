PORTNAME=	cliphist
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	5
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wayland clipboard manager
WWW=		https://github.com/sentriz/cliphist

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	sentriz
GH_TUPLE=	etcd-io:bbolt:v1.3.9:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:image:v0.21.0:golang_image/vendor/golang.org/x/image \
		golang:sys:v0.26.0:golang_sys/vendor/golang.org/x/sys \
		golang:tools:v0.24.0:golang_tools/vendor/golang.org/x/tools \
		rogpeppe:go-internal:v1.12.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sentriz:flagconf:v0.1.9:sentriz_flagconf/vendor/go.senan.xyz/flagconf
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	FZF
OPTIONS_DEFAULT=FZF

FZF_DESC=		Script with only unique lines and previews
FZF_RUN_DEPENDS=	fzf:textproc/fzf \
			wl-copy:x11/wl-clipboard
FZF_PLIST_FILES=	bin/${PORTNAME}-fzf

post-install-FZF-on:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/${FZF_PLIST_FILES:T} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
