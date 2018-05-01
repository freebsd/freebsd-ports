# Created by: Dominik Rothert <dr@domix.de>
# $FreeBSD$

PORTNAME=	xtermset
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/clts/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamically change some settings of an xterm

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}"
USES=		gmake

.include <bsd.port.mk>
