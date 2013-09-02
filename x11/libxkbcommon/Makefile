# $FreeBSD$

PORTNAME=	libxkbcommon
PORTVERSION=	0.3.1
CATEGORIES=	x11
MASTER_SITES=	http://xkbcommon.org/download/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Keymap handling library for toolkits and window systems

LICENSE=	MIT

USES=		gmake bison pathfix

GNU_CONFIGURE=	yes
USE_XZ=		yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--without-default-layout \
		--without-default-model \
		--without-default-options \
		--without-default-rules \
		--without-default-variant \
		--without-doxygen

.include <bsd.port.mk>
