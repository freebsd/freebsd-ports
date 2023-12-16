PORTNAME=	wallutils
DISTVERSION=	5.12.7
PORTREVISION=	3
CATEGORIES=	x11 wayland

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Utilities for handling monitors, resolutions, wallpapers and timed wallpapers
WWW=		https://github.com/xyproto/wallutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libX11.so:x11/libX11

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xyproto
GH_TUPLE=	antchfx:xmlquery:v1.3.8:antchfx_xmlquery/vendor/github.com/antchfx/xmlquery \
		antchfx:xpath:v1.2.0:antchfx_xpath/vendor/github.com/antchfx/xpath \
		anthonynsimon:bild:v0.13.0:anthonynsimon_bild/vendor/github.com/anthonynsimon/bild \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		fatih:color:v1.15.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:v0.7.0:golang_image/vendor/golang.org/x/image \
		golang:net:v0.7.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.8.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.9.0:golang_text/vendor/golang.org/x/text \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.18:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		stretchr:powerwalk:bceb9d014549:stretchr_powerwalk/vendor/github.com/stretchr/powerwalk \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v1.22.5:urfave_cli/vendor/github.com/urfave/cli \
		xyproto:env:v2.0.0:xyproto_env_v2/vendor/github.com/xyproto/env \
		xyproto:heic:v1.0.0:xyproto_heic/vendor/github.com/xyproto/heic
GL_TUPLE=	https://gitlab.howett.net:go:plist:1454fab16a0642638feb0ae98c41f79eccb2a20a:go_plist/vendor/howett.net/plist
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
		./cmd/xml2stw \
		${NULL}
PLIST_FILES=	${GO_TARGET:S,./cmd,bin,} \
		share/man/man1/getdpi.1.gz \
		share/man/man1/vram.1.gz

OPTIONS_DEFINE=		HEIF
OPTIONS_DEFAULT=	HEIF

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_USES=		pkgconfig
HEIF_VARS=		GO_TARGET+=./cmd/heic2stw

post-patch:
# Respect PREFIX for wallpapers
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/cmd/heic2stw/main.go \
		${WRKSRC}/collections.go

post-install:
	${INSTALL_MAN} ${WRKSRC}/cmd/getdpi/getdpi.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/cmd/vram/vram.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
