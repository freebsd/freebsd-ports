# Created by: Volker Stolz <vs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	X11
PORTVERSION=	1.6.1.1
PORTREVISION=	3
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the X11 graphics library

LICENSE=	BSD

USE_CABAL=	data-default
USE_XORG=	x11 xrandr xext

OPTIONS_DEFINE=		XINERAMA
OPTIONS_DEFAULT=	XINERAMA

XINERAMA_DESC=	Build with Xinerama support

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=		xinerama
CONFIGURE_ARGS+=	--configure-option="--with-xinerama"
.else
CONFIGURE_ARGS+=	--configure-option="--without-xinerama"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
