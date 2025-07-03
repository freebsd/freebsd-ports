PORTNAME=	wayout
DISTVERSION=	1.1.3
PORTREVISION=	20
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~shinyzenith/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
# XXX Teach USES=cargo to not override default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple tool to manage output modes
WWW=		https://git.sr.ht/~shinyzenith/wayout

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
