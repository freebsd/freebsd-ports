PORTNAME=	xtermset
PORTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	SF/clts/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamically change some settings of an xterm
WWW=		https://sourceforge.net/projects/clts/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}"
USES=		gmake

.include <bsd.port.mk>
