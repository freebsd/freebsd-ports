# $FreeBSD$

PORTNAME=	wallutils
DISTVERSION=	5.8.3
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Utilities for handling monitors, resolutions, wallpapers and timed wallpapers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/X11/Xmu/CurUtil.h:x11-toolkits/libXmu \
		${LOCALBASE}/include/X11/Xcursor/Xcursor.h:x11/libXcursor \
		${LOCALBASE}/include/X11/bitmaps/gray:x11/xbitmaps \
		${LOCALBASE}/include/X11/Xatom.h:x11/xorgproto
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libX11.so:x11/libX11 \
		libXpm.so:x11/libXpm

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xyproto
GH_TUPLE=	anthonynsimon:bild:v0.11.1:anthonynsimon_bild/vendor/github.com/anthonynsimon/bild \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man/v2 \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		golang:image:e7c1f5e7dbb8:golang_image/vendor/golang.org/x/image \
		golang:sys:52ab43148777:golang_sys/vendor/golang.org/x/sys \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		russross:blackfriday:v2.0.1:russross_blackfriday/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		stretchr:powerwalk:bceb9d014549:stretchr_powerwalk/vendor/github.com/stretchr/powerwalk \
		urfave:cli:v1.22.1:urfave_cli/vendor/github.com/urfave/cli \
		xyproto:event:a3d8ddca97ef:xyproto_event/vendor/github.com/xyproto/event \
		xyproto:gnometimed:745a6701ce92:xyproto_gnometimed/vendor/github.com/xyproto/gnometimed \
		xyproto:imagelib:bbbf5649f300:xyproto_imagelib/vendor/github.com/xyproto/imagelib \
		xyproto:palgen:f8cafa988771:xyproto_palgen/vendor/github.com/xyproto/palgen \
		xyproto:simpletimed:17a9b15a6cbc:xyproto_simpletimed/vendor/github.com/xyproto/simpletimed \
		xyproto:xpm:2cc4223960ab:xyproto_xpm/vendor/github.com/xyproto/xpm
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
