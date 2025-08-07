PORTNAME=	wallutils
DISTVERSIONPREFIX=	v
DISTVERSION=	5.14.2
PORTREVISION=	2
CATEGORIES=	x11 wayland

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Utilities for handling monitors, resolutions, wallpapers and timed wallpapers
WWW=		https://github.com/xyproto/wallutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libX11.so:x11/libX11

USES=		go:modules pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	xyproto
GH_TUPLE=	antchfx:xmlquery:v1.4.4:antchfx_xmlquery/vendor/github.com/antchfx/xmlquery \
		antchfx:xpath:v1.3.4:antchfx_xpath/vendor/github.com/antchfx/xpath \
		anthonynsimon:bild:v0.14.0:anthonynsimon_bild/vendor/github.com/anthonynsimon/bild \
		cpuguy83:go-md2man:v2.0.7:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		fatih:color:v1.18.0:fatih_color/vendor/github.com/fatih/color \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:v0.29.0:golang_image/vendor/golang.org/x/image \
		golang:net:v0.42.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.34.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.27.0:golang_text/vendor/golang.org/x/text \
		mattn:go-colorable:v0.1.14:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		stretchr:powerwalk:bceb9d014549:stretchr_powerwalk/vendor/github.com/stretchr/powerwalk \
		urfave:cli:v1.22.17:urfave_cli/vendor/github.com/urfave/cli \
		xyproto:env:v2.5.3:xyproto_env_v2/vendor/github.com/xyproto/env \
		xyproto:heic:v1.0.0:xyproto_heic/vendor/github.com/xyproto/heic
GL_TUPLE=	https://gitlab.howett.net:go:plist:5afcd134990e1c90a92bac94906f74af0b10042d:go_plist/vendor/howett.net/plist
GO_TARGET=	./cmd/getdpi \
		./cmd/lscollection \
		./cmd/lsmon \
		./cmd/lstimed \
		./cmd/lswallpaper \
		./cmd/setcollection \
		./cmd/setrandom \
		./cmd/settimed \
		./cmd/setwallpaper \
		./cmd/timedinfo \
		./cmd/vram \
		./cmd/wayinfo \
		./cmd/xinfo \
		./cmd/xml2stw

PLIST_FILES=	${GO_TARGET:S,./cmd,bin,}
PLIST_FILES+=	${GO_TARGET:S,./cmd,share/man/man1,:S,$,.1.gz,}

OPTIONS_DEFINE=		HEIF
OPTIONS_DEFAULT=	HEIF

# Using [HEIF_VARS= GO_TARGET+=./cmd/heic2stw] causes post-install to fail parsing instalation of heic2stw.1 manual
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MHEIF}
LIB_DEPENDS+=	libheif.so:graphics/libheif
GO_TARGET+=	./cmd/heic2stw
.endif

post-patch:
# Respect PREFIX for wallpapers
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/cmd/heic2stw/main.go \
		${WRKSRC}/collections.go

post-install:
.for _target in ${GO_TARGET:S,./cmd,/cmd,}
	${INSTALL_MAN} ${WRKSRC}/${_target}/${_target:T}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>
