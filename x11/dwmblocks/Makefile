# x11/dwmblocks

PORTNAME=	dwmblocks
DISTVERSION=	g20240823
CATEGORIES=	x11

MAINTAINER=	echo@lethedata.com
COMMENT=	Modular status bar for dwm
WWW=		https://github.com/torrinfail/dwmblocks/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libX11.so:x11/libX11

USES=		xorg

USE_GITHUB=	yes
GH_ACCOUNT=	torrinfail
GH_TAGNAME=	8cedd22

USE_XORG=	x11

PLIST_FILES=	bin/dwmblocks

pre-everything::
	@${ECHO_MSG} "You can build st with your own blocks.h using the BLK_CONF knob:"
	@${ECHO_MSG} "make BLK_CONF=/path/to/st/blocks.h install clean"
	@${ECHO_MSG} "Signal = 65 + Update Signal number"

.if defined(BLK_CONF)
post-extract:
	@${ECHO_MSG} "creating symlink blocks.h from ${BLK_CONF}"
	@${LN} -sf ${BLK_CONF} ${WRKSRC}/blocks.h
.endif

post-patch:
	# Uncomment FreeBSD-specific LDFLAGS
	@${REINPLACE_CMD} \
		-e "7 s/^#//" \
		-e '3s/:=/+=/' \
		-e '4s/:=/+=/' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dwmblocks

.include <bsd.port.mk>
