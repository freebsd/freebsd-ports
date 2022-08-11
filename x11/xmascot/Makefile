PORTNAME=	xmascot
PORTVERSION=	2.6a.20200830
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	nyan@FreeBSD.org
COMMENT=	Moving mascot on your X11 screen

LICENSE=	UNKNOWN
LICENSE_NAME=	XMascot
LICENSE_FILE=	${WRKSRC}/README.jp
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		iconv:build imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
USE_GITHUB=	yes
GH_ACCOUNT=	nyan-

OPTIONS_DEFINE=	DOCS

X11_LIBDIR=	${STAGEDIR}${PREFIX}/lib/X11

post-install:
	@${MKDIR} ${X11_LIBDIR}/ja_JP.EUC/app-defaults
	${INSTALL_DATA} ${X11_LIBDIR}/ja_JP.eucJP/app-defaults/XMascot \
		${X11_LIBDIR}/ja_JP.EUC/app-defaults
	@${MKDIR} ${X11_LIBDIR}/ja_JP.UTF-8/app-defaults
	${ICONV_CMD} -f euc-jp -t utf-8 ${X11_LIBDIR}/ja_JP.eucJP/app-defaults/XMascot > \
		${X11_LIBDIR}/ja_JP.UTF-8/app-defaults/XMascot

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${LICENSE_FILE} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
