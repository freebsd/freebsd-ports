PORTNAME=	wallutils
DISTVERSION=	5.9.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Utilities for handling monitors, resolutions, wallpapers and timed wallpapers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libX11.so:x11/libX11

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xyproto
GH_TUPLE=	anthonynsimon:bild:v0.11.1:anthonynsimon_bild/vendor/github.com/anthonynsimon/bild \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man/v2 \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		golang:image:58c23975cae1:golang_image/vendor/golang.org/x/image \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		russross:blackfriday:v2.0.1:russross_blackfriday/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		stretchr:powerwalk:bceb9d014549:stretchr_powerwalk/vendor/github.com/stretchr/powerwalk \
		urfave:cli:v1.22.1:urfave_cli/vendor/github.com/urfave/cli \
		xyproto:event:a3d8ddca97ef:xyproto_event/vendor/github.com/xyproto/event \
		xyproto:gnometimed:745a6701ce92:xyproto_gnometimed/vendor/github.com/xyproto/gnometimed \
		xyproto:simpletimed:17a9b15a6cbc:xyproto_simpletimed/vendor/github.com/xyproto/simpletimed
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
		./cmd/wayinfo \
		./cmd/xinfo \
		./cmd/xml2stw \
		${NULL}
PLIST_FILES=	${GO_TARGET:S,./cmd,bin,}

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' ${WRKSRC}/collections.go

.include <bsd.port.mk>
