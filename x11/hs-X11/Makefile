# Created by: Volker Stolz <vs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	X11
PORTVERSION=	1.5.0.1
PORTREVISION=	3
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	X11 bindings for Haskell programs

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	syb
USE_XORG=	x11 xext sm

OPTIONS_DEFINE=		XINERAMA
OPTIONS_DEFAULT=	XINERAMA

XINERAMA_DESC=		Build with Xinerama support

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=		xinerama
CONFIGURE_ARGS+=	--configure-option="--with-xinerama"
.else
CONFIGURE_ARGS+=	--configure-option="--without-xinerama"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
