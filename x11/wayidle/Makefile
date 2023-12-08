PORTNAME=	wayidle
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~whynothugo/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
# XXX Teach USES=cargo to not override default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wait for wayland compositor idle timeouts
WWW=		https://sr.ht/~whynothugo/wayidle

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE.md

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
