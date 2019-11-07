# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xmascot
PORTVERSION=	2.6a
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://cclub-flying.dsl.gr.jp/products/xmascot/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Moving mascot on your X11 screen

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAKE_ARGS=	MAKE="${MAKE_CMD}"

# Unbreak parallel (-jX) builds: do not use unsafe MakeSubdirs() macro
post-patch:
	@${REINPLACE_CMD} -e 's/MakeSubdirs(/Named&$$(IMAGELIB),/' \
		${WRKSRC}/Imakefile

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/ja_JP.EUC/app-defaults
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/XMascot \
		${STAGEDIR}${PREFIX}/lib/X11/ja_JP.EUC/app-defaults

.include <bsd.port.mk>
