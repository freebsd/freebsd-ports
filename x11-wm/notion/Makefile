PORTNAME=	notion
DISTVERSION=	4.0.3
CATEGORIES=	x11-wm

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Tiling tabbed window manager
WWW=		https://notionwm.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		gettext gmake localbase lua pkgconfig readline xorg
USE_GITHUB=	yes
GH_ACCOUNT=	raboof
USE_XORG=	ice sm x11 xext

BINARY_ALIAS=	sed=gsed
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS XINERAMA XRANDR
OPTIONS_DEFAULT=	XINERAMA XRANDR
OPTIONS_SUB=		yes

XINERAMA_DESC=	Xinerama module support
XRANDR_DESC=	Xrandr module support

XINERAMA_USE=	XORG=xinerama
XRANDR_USE=	XORG=xrandr

.include <bsd.port.options.mk>

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^_install:/,/^$$/ d' ${WRKSRC}/Makefile
.endif
.if !${PORT_OPTIONS:MXINERAMA}
	@${REINPLACE_CMD} -e 's|mod_xinerama||' ${WRKSRC}/modulelist.mk
.endif
.if !${PORT_OPTIONS:MXRANDR}
	@${REINPLACE_CMD} -e 's|mod_xrandr||' ${WRKSRC}/modulelist.mk
.endif

.include <bsd.port.mk>
