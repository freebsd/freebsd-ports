PORTNAME=	clipman
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.5
PORTREVISION=	2
CATEGORIES=	x11 wayland

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Simple clipboard manager for Wayland
WWW=		https://github.com/chmouel/clipman

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	wl-copy:x11/wl-clipboard

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	chmouel

GH_TUPLE=       \
                alecthomas:kingpin:v2.4.0:alecthomas_kingpin_v2/vendor/github.com/alecthomas/kingpin/v2 \
                alecthomas:units:0f3dac36c52b:alecthomas_units/vendor/github.com/alecthomas/units \
                golang:text:v0.22.0:golang_text/vendor/golang.org/x/text \
                kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
                xhit:go-str2duration:v2.1.0:xhit_go_str2duration_v2/vendor/github.com/xhit/go-str2duration/v2

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
