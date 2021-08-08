# x11/dwmblocks

PORTNAME=	dwmblocks
DISTVERSION=	g20201227
CATEGORIES=	x11

MAINTAINER=	echo@lethedata.com
COMMENT=	Modular status bar for dwm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libX11.so:x11/libX11

USES=		xorg

USE_GITHUB=	yes
GH_ACCOUNT=	torrinfail
GH_TAGNAME=	96cbb45

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
	@${REINPLACE_CMD} -E \
		-e "s|(LDFLAGS[[:space:]]*)= |\1= -L/usr/local/lib -I/usr/local/include |" \
		-e "s|output|all|" \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dwmblocks

.include <bsd.port.mk>
