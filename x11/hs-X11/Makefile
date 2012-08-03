# New ports collection makefile for:	hs-x11-ghc
# Date created:				2007-09-03
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	X11
PORTVERSION=	1.5.0.1
PORTREVISION=	2
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=		xinerama
CONFIGURE_ARGS+=	--configure-option="--with-xinerama"
.else
CONFIGURE_ARGS+=	--configure-option="--without-xinerama"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
