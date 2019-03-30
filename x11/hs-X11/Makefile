# Created by: Volker Stolz <vs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	X11
PORTVERSION=	1.8
PORTREVISION=	5
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the X11 graphics library

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	data-default
USE_XORG=	x11 xrandr xext

FLAGS_DEFINE=		XINERAMA
FLAGS_DEFAULT=		XINERAMA

XINERAMA_DESC=			Build with Xinerama support
XINERAMA_FLAG_XORG=		xinerama
XINERAMA_FLAG_CONFIGURE_ON=	--configure-option="--with-xinerama"
XINERAMA_FLAG_CONFIGURE_OFF=	--configure-option="--without-xinerama"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
